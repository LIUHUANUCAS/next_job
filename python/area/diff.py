#!/bin/python
# -*- coding: UTF-8 -*-

from decimal import ConversionSyntax
import sys
import copy

from numpy import insert

reload(sys)
sys.setdefaultencoding('utf8')

# table name for update
tableName = 'risk'
SQLCOMMENT = "--"

ADD_LABEL = 'add'
UPDATE_LABEL = 'update'
DEL_LABEL = 'del'
NONE_LABEL = 'none'

level_map = {
    '1': "中",
    '2': "高",
    '0': "低",
}


update_log_map = {
    '0': "无需更新",
    '1': "添加记录",
    '2': "删除记录",
    '3': "更新记录",
}

row_keys = ['qhdm', 'risk', 'sfmc', 'dsmc', 'rksj']


def get_level_label(level):
    l = str(level)
    if l not in level_map.keys():
        return "无"

    return level_map[l]


def load(filename):
    data_dict = {}
    with open(filename) as f:
        for line in f.readlines():
            line = line.strip().split(',')
            prov = line[2].decode('utf-8')
            city = line[3].decode('utf-8')
            # print(SQLCOMMENT+'' + prov+','+city)
            row_dict = {row_keys[i]: line[i] for i in range(len(row_keys))}
            data_dict[line[0]] = row_dict
    return data_dict


def intercept(A, B):
    return set(A.keys()) & set(B.keys())


def set_substract(A, B):
    return set(A.keys()) - set(B.keys())


def sql_comment_print(d):
    s = [str(e) for k, e in d.items()]
    print("%s %s", SQLCOMMENT, s)


def print_with_sql_comment(type, s):
    print("%s %d %s" % (SQLCOMMENT, type, s))


def getAction(newLevel, oldLevel):
    a, b = int(str(newLevel)), int(str(oldLevel))
    if a < b:
        return "降"
    elif a > b:
        return "升"
    return "保持"


def generate_add_sql(a):
    oldLevel = a['old_risk']
    newRow = row_keys+['riskmc']
    level_label = get_level_label(a['risk'])
    b = copy.deepcopy(a)
    b['riskmc'] = level_label
    insertValues = ["\'%s\'" % b[name] for name in newRow]
    s = "insert into %s(%s) values(%s);" % (
        tableName, ','.join(newRow), ','.join(insertValues))
    # print("hell",a['risk'])
    log = "%s%s升为%s风险" % (a['sfmc'], a['dsmc'], level_label)
    return (s, log)


def generate_del_sql(a):
    oldLevel = a['old_risk']
    s = "delete from %s where qhdm = '%s'; %s %s-%s-%s" % (
        tableName, a['qhdm'], SQLCOMMENT, a['sfmc'], a['dsmc'], get_level_label(oldLevel))
    # print(s)
    new_risk_label = get_level_label(a['risk'])
    old_risk_label = get_level_label(oldLevel)
    up = getAction(a['risk'], a['old_risk'])
    log = "%s%s由%s风险%s为%s风险" % (
        a['sfmc'], a['dsmc'], old_risk_label, up, new_risk_label)
    return (s, log)


def generate_update_sql(a):
    oldLevel = a['old_risk']
    # print(s)
    up = getAction(a['risk'], oldLevel)
    new_level_lable = get_level_label(a['risk'])
    old_level_lable = get_level_label(oldLevel)
    s = "update %s set risk = '%s' where qhdm = '%s'; %s %s-%s-%s->%s" % (
        tableName, a['risk'], a['qhdm'], SQLCOMMENT, a['sfmc'], a['dsmc'], old_level_lable, new_level_lable)

    log = "%s%s由%s风险%s为%s风险" % (
        a['sfmc'], a['dsmc'], old_level_lable, up, new_level_lable)
    return s, log


def generate_nosql(a):
    s = [SQLCOMMENT, 'nosql'] + [str(v) for k, v in a.items()]
    s = ','.join([str(e) for e in s])
    # print(s)
    old_level_label = get_level_label(a['old_risk'])
    new_level_label = get_level_label(a['risk'])
    up = getAction(a['risk'], a['old_risk'])
    log = "%s%s由%s风险%s为%s风险" % (
        a['sfmc'], a['dsmc'], old_level_label, up, new_level_label)
    return s, log


gen_map = {
    'add': [generate_add_sql, 1],
    "del": [generate_del_sql, 2],
    "update": [generate_update_sql, 3],
    "none": [generate_nosql, 0],


}


def generate_sql(a, type):
    if type in gen_map.keys():
        return gen_map[type][0](a)

    return SQLCOMMENT, SQLCOMMENT


def add_log(update_map, log, type):
    if type not in update_map.keys():
        update_map[type] = []
    update_map[type].append(log)


def add_result(result_map, result, type):
    if type not in result_map.keys():
        result_map[type] = []
    result_map[type].append(result)


def diff_data(old, new):
    result = {}
    update_log = {}
    b_a = set_substract(new, old)

    # 1. B - A , just add rows
    for key in b_a:
        # result.append(new[key] + ['add'])
        deepmap = copy.deepcopy(new[key])
        deepmap['type'] = ADD_LABEL
        deepmap['old_risk'] = '0'
        # result.append(deepmap)
        add_result(result, deepmap, ADD_LABEL)
        _, log = generate_add_sql(deepmap)
        add_log(update_log, log, ADD_LABEL)

    # 2. A - B , just delete
    a_b = set_substract(old, new)
    for key in a_b:
        # result.append(old[key] + ['del'])
        deepmap = copy.deepcopy(old[key])
        deepmap['type'] = DEL_LABEL
        deepmap['risk'] = '0'
        deepmap['old_risk'] = old[key]['risk']
        # result.append(deepmap)
        add_result(result, deepmap, DEL_LABEL)
        _, log = generate_del_sql(deepmap)
        # update_log.append(log)
        add_log(update_log, log, DEL_LABEL)

    # 3. A and B
    comm = intercept(new, old)
    for key in comm:
        level_old = old[key]['risk']
        level_new = new[key]['risk']
        if level_old != level_new:
            level = level_new

            deepmap = copy.deepcopy(old[key])
            deepmap['type'] = UPDATE_LABEL
            deepmap['risk'] = level
            deepmap['old_risk'] = level_old
            add_result(result, deepmap, UPDATE_LABEL)
            # result.append(deepmap)
            _, log = generate_update_sql(deepmap)
            add_log(update_log, log, UPDATE_LABEL)
        else:
            deepmap = copy.deepcopy(old[key])
            deepmap['type'] = NONE_LABEL
            deepmap['old_risk'] = level_old
            add_result(result, deepmap, NONE_LABEL)
            # result.append(deepmap)
            generate_nosql(deepmap)

    return result, update_log


def get_type_sql_log(array, type):
    sql_list, log_list = [], []
    for item in array:
        res = generate_sql(item, type)
        sql_list.append(res[0])
        log_list.append(res[1])
    return sql_list, log_list


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print('python %s %s %s' % (sys.argv[0], 'new_file', 'old_file'))
        sys.exit(-1)
    newfile = sys.argv[1]
    oldfile = sys.argv[2]
    new = load(newfile)
    old = load(oldfile)
    print("%s update %s" % (SQLCOMMENT, newfile))
    result_map, log = diff_data(old, new)
    # result.sort(key=lambda x: int(x['qhdm']))
    # print(result)
    logs = {}
    for type, result in result_map.items():
        result.sort(key=lambda x: int(x['qhdm']))
        sql_list, log_list = get_type_sql_log(result, type)
        for sql in sql_list:
            print(sql)
        logs[type] = log_list

    # 修改日志
    print('----------更新记录----------')
    print('/***\n')
    i = 0
    for type, log in logs.items():
        i += 1
        update_log_label = update_log_map[str(gen_map[type][1])]
        print('%d.%s:' % (i, update_log_label))
        for idx, item in enumerate(log):
            print('\t%d) %s' % (idx+1, item))
            # print_with_sql_comment(gen_map[type][1], item)
    print('**/\n')
    # "中高风险区域表已更新，更新内容：1）删除记录：河南省商丘市由中风险降为低风险 2）新增记录：吉林省白城市升为中风险"

    # 1): 更新内容: prov-city-由$high/$mid风险降低为$low风险
    # 2): 新增记录: prov-city升为$high/$mid风险"

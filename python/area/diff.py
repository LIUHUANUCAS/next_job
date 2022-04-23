#!/bin/python
# -*- coding: UTF-8 -*-

from decimal import ConversionSyntax
import sys
import copy

reload(sys)
sys.setdefaultencoding('utf8')

## table name for update 
tableName='risk'
SQLCOMMENT="-- "

level_map = {
    '1': "中",
    '2': "高",
    '0': "低",
}


def get_level_label(level):
    l = str(level)
    if l not in level_map.keys():
        return "无"

    return level_map[l]

row_keys = ['qhdm' ,'risk', 'sfmc' , 'dsmc' , 'gxsj']
def load(filename):
    data_dict = {}
    with open(filename) as f:
        for line in f.readlines():
            line = line.strip().split(',')
            # print(line)
            prov = line[2].decode('utf-8')
            city = line[3].decode('utf-8')
            print(SQLCOMMENT+'' + prov+','+city)
            # row = [line[0],line[1],prov,city,line[4]]
            row_dict = {
                row_keys[i]:line[i] for i in range(len(row_keys)) 
            }
            # print(row_dict)
            data_dict[line[0]] = row_dict
    return data_dict



def intercept(A,B):
    return set(A.keys()) & set(B.keys())

def set_substract(A,B):
    return set(A.keys()) - set(B.keys())

def sql_comment_print(d):
    s = [str(e) for k,e in d.items()]
    print("%s %s",SQLCOMMENT,s)

def print_with_sql_comment(s):
    print("%s %s"%(SQLCOMMENT,s))


def getAction(newLevel, oldLevel):
    a, b = int(str(newLevel)),int(str(oldLevel))
    if a < b:
        return "降低"
    elif a > b:
        return "升级"
    return "保持"

def generate_add_sql(a):
    oldLevel = a['old_risk']
    s = "insert into %s(qhdm ,risk, sfmc , dsmc , gxsj) values('%s','%s','%s','%s','%s');"%(tableName,a['qhdm'],a['risk'],a['sfmc'],a['dsmc'],a['gxsj'])
    # print("hell",a['risk'])
    level_label = get_level_label(a['risk'])
    log = "%s%s升为%s风险" %(a['sfmc'],a['dsmc'],level_label)
    return (s, log)

def generate_del_sql(a):
    oldLevel = a['old_risk']
    s = "delete from %s where qhdm = '%s'; %s %s-%s" %(tableName,a['qhdm'],SQLCOMMENT ,a['sfmc'],a['dsmc'])
    # print(s)
    new_risk_label = get_level_label(a['risk'])
    old_risk_label = get_level_label(oldLevel)
    up = getAction(a['risk'],a['old_risk'])
    log = "%s%s由%s风险%s为%s风险"%(a['sfmc'],a['dsmc'],old_risk_label,up,new_risk_label)
    return (s,log)

def generate_update_sql(a):
    oldLevel = a['old_risk']
    s = "update %s set risk = '%s' where qhdm = '%s'; %s %s-%s" %(tableName,a['risk'],a['qhdm'],SQLCOMMENT,a['sfmc'],a['dsmc'])
    # print(s)
    up = getAction(a['risk'],oldLevel)
    new_level_lable = get_level_label(a['risk'])
    old_level_lable = get_level_label(oldLevel)

    log = "%s%s由%s风险%s为%s风险"%(a['sfmc'],a['dsmc'],old_level_lable,up,new_level_lable)
    return s,log

def generate_nosql(a):
    s = [SQLCOMMENT] + [str(v) for k,v in a.items()]
    s = ','.join([str(e) for e in s])
    # print(s)
    old_level_label = get_level_label(a['old_risk'])
    new_level_label = get_level_label(a['risk'])
    up = getAction(a['risk'],a['old_risk'])
    log = "%s%s由%s风险%s为%s风险"%(a['sfmc'],a['dsmc'],old_level_label,up,new_level_label)
    return s ,log 

gen_map = {
    'add':generate_add_sql,
    "del": generate_del_sql,
    "update":generate_update_sql,
    "none":generate_nosql,
}


def generate_sql(a,type):
    
    if type in gen_map.keys():
        return gen_map[type](a)
    return SQLCOMMENT,SQLCOMMENT

def add_log(update_map,log,type):
    if type not in update_map.keys():
        update_map[type] = []
    update_map[type].append(log)

def diff_data(old,new):
    result = []
    update_log = {}
    b_a = set_substract(new,old)
    #1. B - A , just add rows 
    for key in b_a: 
        # result.append(new[key] + ['add'])
        deepmap = copy.deepcopy(new[key])
        deepmap['type'] = 'add'
        deepmap['old_risk'] = '0'
        result.append(deepmap)
        _, log = generate_add_sql(deepmap)
        add_log(update_log,log,'add')

    # 2. A - B , just delete     
    a_b = set_substract(old,new)
    for key in a_b:
        # result.append(old[key] + ['del'])
        deepmap = copy.deepcopy(old[key])
        deepmap['type'] = 'del'
        deepmap['risk'] = '0'
        deepmap['old_risk'] = old[key]['risk']
        result.append(deepmap)
        _,log = generate_del_sql(deepmap)
        # update_log.append(log)
        add_log(update_log,log,'del')
    
    # 3. A and B 
    comm = intercept(new,old)
    for key in comm:
        level_old = old[key]['risk']
        level_new = new[key]['risk']
        if level_old != level_new:
            level = level_new

            deepmap = copy.deepcopy(old[key])
            deepmap['type'] = 'update'
            deepmap['risk'] = level 
            deepmap['old_risk'] = level_old
            result.append(deepmap)
            _,log = generate_update_sql(deepmap)
            add_log(update_log,log,'update')
        else :
            deepmap = copy.deepcopy(old[key])
            deepmap['type'] = 'none'
            deepmap['old_risk'] = level_old
            result.append(deepmap)
            generate_nosql(deepmap)
    return result,update_log


newfile=sys.argv[1]
oldfile=sys.argv[2]
new = load(newfile)
old = load(oldfile)
print("%s update %s"%(SQLCOMMENT,newfile))
result,log  = diff_data(old,new)
result.sort(key=lambda x: int(x['qhdm']))
# print(result)

for e in result :
    # print(e)
    s = generate_sql(e,e['type'])
    print(s[0])
    print_with_sql_comment(s[1])
    print('-----------------------')

# for e in result:
#     s = generate_sql(e,e['type'])
#     print(s[1])


# "中高风险区域表已更新，更新内容：1）删除记录：河南省商丘市由中风险降为低风险 2）新增记录：吉林省白城市升为中风险"


# 1): 更新内容: prov-city-由$high/$mid风险降低为$low风险
# 2): 新增记录: prov-city升为$high/$mid风险"
 

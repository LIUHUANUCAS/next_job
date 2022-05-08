#!/usr/bin/python
# -*- coding: UTF-8 -*-

import datetime
import json
import sys
import math

# reload(sys)
# sys.setdefaultencoding('utf8')

# today = '2022-04-23'
# today = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
whitelist = ['北京市', '上海市', '重庆市', '天津市']
row_keys = ['qhdm', 'risk', 'sfmc', 'dsmc', 'rksj']
cityname = 'city-code.txt'
data_source_url = 'https://bmfw.www.gov.cn/yqfxdjcx/risk.html'


def get_half_time():
    now = datetime.datetime.now()
    timestamp = now.timestamp()
    hour = timestamp//(60*60)*60*60
    minute = now.minute
    m = math.ceil(minute/30)*30
    nextHalfHour = hour + m * 60
    d = datetime.datetime.fromtimestamp(
        nextHalfHour).strftime('%Y-%m-%d %H:%M:%S')
    return d


def load_json(filename):
    with open(filename) as f:
        data = json.load(f)
        return data

# {cityname:citycode} example:{'上海市':'310000'}


def load_city_name_map(filename):
    with open(filename) as f:
        city_map = {}
        for line in f.readlines():
            line = line.strip()
            fields = line.split(' ')
            name = fields[1]
            city_map[name] = fields[0]
        return city_map


def generate_format_data(data, city_code, flag):
    res = {}
    today = get_half_time()
    # [qhdm ,risk, sfmc , dsmc , rksj]
    for e in data:
        prov = e['province']
        city = e['city']
        query_city = city
        if prov in whitelist:
            city = ''
            query_city = prov
        if city_code[query_city] is not None:
            code = city_code[query_city]
            prov_decode = prov
            line = [code, str(flag), prov_decode, city, today]
            row_dict = {row_keys[i]: line[i]
                        for i in range(len(row_keys))}
            res[code] = row_dict
    return res


def merge_middle_high(mid, high):
    res = mid
    for k, v in high.items():
        if k in mid.keys():
            mid[k]['risk'] = max(mid[k]['risk'], v['risk'])
        else:
            res[k] = v
    return res


def get_list(data_dict):
    res = [e for _, e in data_dict.items()]
    res.sort(key=lambda x: int(x['qhdm']))
    return res


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('data source url:', data_source_url)
        print('usage: python %s %s' % (sys.argv[0], 'loc_risk_filename'))
        sys.exit(-1)
    filename = '0423.txt'
    filename = sys.argv[1]
    data = load_json(filename)
    high = data['data']['highlist']
    mid = data['data']['middlelist']
    end_update_time = data['data']['end_update_time']
    print('last_update_at', end_update_time)
    city_code_map = load_city_name_map(cityname)
    # print(city_code_map)
    high_map = generate_format_data(high, city_code_map, 2)
    mid_map = generate_format_data(mid, city_code_map, 1)

    result_loc_map = merge_middle_high(mid_map, high_map)

    loc_list = get_list(result_loc_map)
    output_filename = datetime.datetime.now().strftime('%Y-%m-%d-%H')
    with open(output_filename+'_new_risk_loc.txt', 'w') as f:
        for e in loc_list:
            row = [e[row_keys[i]] for i in range(len(row_keys))]

            s = ','.join(row)
            f.write(s+'\n')

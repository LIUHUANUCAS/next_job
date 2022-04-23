#!/usr/bin/python
# -*- coding: UTF-8 -*-

import datetime
import json 
import sys

reload(sys)

sys.setdefaultencoding('utf8')

today = '2022-04-23'
today = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
whitelist = ['北京市','上海市','重庆市','天津市']
def load_json(filename):
    with open(filename) as f :
        data = json.load(f)
        return data

def load_city_name_map(filename):
    with open(filename) as f :
        city_map ={}
        for line in f.readlines():
            line = line.strip()
            fields = line.split(' ')
            name = fields[1].decode('utf-8')
            city_map[name] = fields[0]
        return city_map

def generate_format_data(data,city_code,flag):
    res = {}
    
    # [qhdm ,risk, sfmc , dsmc , gxsj]
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
            res[code]= [code,flag,prov_decode,city,today] 
    print(res)
    return res

def merge_middle_high(mid,high):
    res = mid 
    for k,v in high.items():
        if k in mid.keys():
            mid[k][1] = max(mid[k][1],v[1])
        else:
            res[k] = v
    return res 

def get_list(data_dict):
    res = [e for _, e  in data_dict.items()]
    res.sort(key=lambda x:int(x[0]))
    return res 

filename='0423.txt'
data = load_json(filename) 
high = data['data']['highlist']
mid = data['data']['middlelist']
cityname='city-code.txt'
print(high)
city_code_map = load_city_name_map(cityname)
print(city_code_map)
high_map = generate_format_data(high,city_code_map,2)
mid_map = generate_format_data(mid,city_code_map,1)
res = merge_middle_high(mid_map,high_map)
# for k,v in res.items():
#     print(k,v)

loc_list = get_list(res)
with open(today+'_new.txt','w') as f:

    for e in loc_list:
        s = ','.join([str(x) for x in e])
        f.write(s+'\n')

# print(merge_middle_high({"0":[-1,2],"1":[0,1],"2":[1,2]}, {"1":[0,2],"2":[1,1],"3":[3,0]}))




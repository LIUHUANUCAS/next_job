#!/usr/bin/python
# -*- coding: utf-8 -*-
# @Time    : 2022/5/12 11:08
# @Author  : Kyln.Wu
# @Email   : kylnwu@qq.com
# @File    : 疫情风险地区查询.py
# @Software: PyCharm
import hashlib
import json
import difflib
import requests
import time
import pandas as pd

citylist = ['浙江省台州市', '湖北省武汉市', '海南省省直辖县级行政单位']
filename = "xzqhdm.csv"
xzqh_table = pd.read_csv(filename)
xzqh_table_p = pd.read_csv("工作簿1.csv")

# import pymssql
# from collections import Counter

# def auto_genxunbao():
#     conn = pymssql.connect(host='192.168.100.79', port='1433', user='gsgl-Suser', password='gSu123!@#', database='gsgl',
#                                charset='utf8')
#     cursor = conn.cursor()
#     print("connect to DB SUCCESSFULLY！！！")
#     executeGenReport = "select concat(sfmc,dsmc) from [gsgl].[dbo].[risk]"
#     cursor.execute(executeGenReport)
#     res = cursor.fetchall()
#     print(res)
#     cursor.close()
#     conn.close()

timestamp = str(int((time.time())))

token = '23y0ufFl5YxIyGrI8hWRUZmKkvtSjLQA'
nonce = '123456789abcdefg'
passid = 'zdww'
key = "3C502C97ABDA40D0A60FBEE50FAAD1DA"

bdCityList = ["北京市", "天津市", "河北省石家庄市", "内蒙古自治区锡林郭勒盟", "吉林省吉林市", "上海市", "浙江省金华市", "浙江省台州市", "安徽省蚌埠市", "山东省菏泽市", "河南省郑州市", "河南省开封市", "河南省商丘市", "河南省信阳市", "河南省周口市",
              "湖北省武汉市", "广东省深圳市", "广东省惠州市", "广西壮族自治区北海市", "广西壮族自治区崇左市", "海南省三亚市", "四川省成都市", "四川省德阳市", "甘肃省兰州市", "甘肃省白银市", "甘肃省定西市", "甘肃省临夏回族自治州", "甘肃省甘南藏族自治州", "新疆维吾尔自治区伊犁哈萨克自治州"]
zxsCityList = ['北京市', '天津市', '上海市', '重庆市']


def get_zdwwsignature():
    zdwwsign = timestamp + 'fTN2pfuisxTavbTuYVSsNJHetwq5bJvC' + \
        'QkjjtiLM2dCratiA' + timestamp
    hsobj = hashlib.sha256()
    hsobj.update(zdwwsign.encode('utf-8'))
    zdwwsignature = hsobj.hexdigest().upper()
    return zdwwsignature


def get_signatureheader():
    has256 = hashlib.sha256()
    sign_header = timestamp + token + nonce + timestamp
    has256.update(sign_header.encode('utf-8'))
    signatureHeader = has256.hexdigest().upper()
    return signatureHeader


def get_datas():
    url = 'https://bmfw.www.gov.cn/bjww/interface/interfaceJson'
    headers = {
        "Accept": "application/json, text/javascript, */*; q=0.01",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "zh-CN,zh;q=0.9",
        "Connection": "keep-alive",
        # "Content-Length": "235",
        "Content-Type": "application/json; charset=UTF-8",
        "Host": "bmfw.www.gov.cn",
        "Origin": "http://bmfw.www.gov.cn",
        "Referer": "http://bmfw.www.gov.cn/yqfxdjcx/risk.html",
        # "Sec-Fetch-Dest": "empty",
        # "Sec-Fetch-Mode": "cors",
        # "Sec-Fetch-Site": "cross-site",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.87 Safari/537.36 SE 2.X MetaSr 1.0",
        "x-wif-nonce": "QkjjtiLM2dCratiA",
        "x-wif-paasid": "smt-application",
        "x-wif-signature": get_zdwwsignature(),
        "x-wif-timestamp": timestamp
    }

    params = {
        'appId': "NcApplication",
        'paasHeader': "zdww",
        'timestampHeader': timestamp,
        'nonceHeader': "123456789abcdefg",
        'signatureHeader': get_signatureheader(),
        'key': "3C502C97ABDA40D0A60FBEE50FAAD1DA"
    }

    print('json:', json)
    print('headers:', headers)
    resp = requests.post(url, headers=headers, json=params)
    datas = resp.text
    return datas


def get_highlist(data):
    highlist = data['data']['highlist']
    highcity = []
    for high in highlist:
        # 判断直辖市为北京北京
        if high['province'] in zxsCityList:
            highcity.append(high['province'])
        else:
            highcity.append(high['province']+high['city'])
    return highcity


def get_city(risk_list):
    city_list = []
    for risk in risk_list:
        prov = risk['province']
        city = risk['city']
        county = risk['county']
        if prov in zxsCityList:
            city_list.append(prov)
        else:
            city_list.append(risk['province']+risk['city'])
        # highcity.append(middle['province']+middle['city']) #此時的highcity包括中高風險
    return city_list


def get_middlelist(data):
    middlelist = data['data']['middlelist']
    middlecity = []
    for middle in middlelist:
        if middle['province'] in zxsCityList:
            middlecity.append(middle['province'])
        else:
            middlecity.append(middle['province']+middle['city'])
        # highcity.append(middle['province']+middle['city']) #此時的highcity包括中高風險
    return middlecity


def get_high_middle_list(data):
    high_middle_city_list = []
    high_city_list = get_highlist(data)
    middle_city_list = get_middlelist(data)
    high_middle_city_list = high_city_list+middle_city_list
    return high_middle_city_list


def match_xzqhdm(citylist):

    xzqh_table_list = xzqh_table.values.tolist()
    xzqh_table_p_list = xzqh_table_p.values.tolist()
    city_return_list = []
    city_return_list_2 = []
    for p in xzqh_table_p_list:
        for c in xzqh_table_list:
            if p[0] != c[0]:
                if str(c[0])[4:6] == '00':
                    if str(p[0])[0:2] == str(c[0])[0:2]:
                        city_return_list.append([c[0], p[1]+c[1]])
    for city in citylist:
        # print(city)
        for row in city_return_list:
            # print(row)
            if(city == row[1]):
                city_return_list_2.append({city: row[0]})

    return city_return_list_2


def is_add_city(riskcity):
    # 判断新增的城市
    insertCityList = []
    for risk in riskcity:
        if risk[0:3] in zxsCityList:
            if risk[0:3] not in bdCityList:
                insertCityList.append(risk[0:3])
        else:
            if risk not in bdCityList:
                insertCityList.append(risk)
    return insertCityList


def is_delete_city(bdCityList):
    # 判断删除的城市
    deleteCityList = []
    for bdCity in bdCityList:
        # print(bdCity[0:3])
        if bdCity[0:3] in zxsCityList:
            if bdCity[0:3] not in riskcity:
                deleteCityList.append(bdCity[0:3])
        else:
            if bdCity not in riskcity:
                deleteCityList.append(bdCity)
    return deleteCityList


if __name__ == '__main__':
    data = get_datas()
    datajson = json.loads(data)
    # highcity = get_highlist(datajson)
    # print(highcity)
    # print(datajson)
    high_middle_city_list = get_high_middle_list(datajson)
    # print(middlecity) #后边改名
    riskcity = list(set(high_middle_city_list))
    # print(riskcity)

    insertCityList = is_add_city(riskcity)
    deleteCityList = is_delete_city(bdCityList)
    print(insertCityList)
    print(deleteCityList)

    a = match_xzqhdm(insertCityList)
    print(a)


# 直辖市没有匹配到代码
# 直辖县的问题还没处理

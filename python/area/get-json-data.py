from bz2 import compress
import hashlib

import datetime
import time
import json
import requests
from copy import deepcopy
import curlify
# function s(t) {
# 	var e = ((new Date)
# 			.getTime() / 1e3)
# 		.toFixed(),
# 		i = "23y0ufFl5YxIyGrI8hWRUZmKkvtSjLQA",
# 		a = "123456789abcdefg",
# 		s = "zdww";
# 	return JSON.stringify(Object.assign({
# 		appId: "NcApplication",
# 		paasHeader: s,
# 		timestampHeader: e,
# 		nonceHeader: a,
# 		signatureHeader: CryptoJS.SHA256(e + i + a + e)
# 			.toString(CryptoJS.enc.Hex)
# 			.toUpperCase()
# 	}, t))
# }


passHeader = "zzdw"
nonceHeader = "123456789abcdefg"
i = "23y0ufFl5YxIyGrI8hWRUZmKkvtSjLQA"
signKey = "QkjjtiLM2dCratiA"

x_wif_nonce = "QkjjtiLM2dCratiA"
x_wif_paasid = "smt-application"
#                         "x-wif-signature": o,
#                         "x-wif-timestamp": n

url = 'https://bmfw.www.gov.cn/bjww/interface/interfaceJson'
x_wif_signature = 'x-wif-signature'
x_wif_timestamp = 'x-wif-timestamp'
timestamp = str(int(time.time()))

# curl 'https://bmfw.www.gov.cn/bjww/interface/interfaceJson' \
#   -H 'Connection: keep-alive' \
#   -H 'sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="98", "Google Chrome";v="98"' \
#   -H 'x-wif-nonce: QkjjtiLM2dCratiA' \
#   -H 'sec-ch-ua-mobile: ?0' \
#   -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.109 Safari/537.36' \
#   -H 'x-wif-paasid: smt-application' \
#   -H 'Content-Type: application/json; charset=UTF-8' \
#   -H 'Accept: application/json, text/javascript, */*; q=0.01' \
#   -H 'x-wif-signature: 29908213EE9B62001D97DC664C0561B7C7522DAED4F6A14CECAB7F4863301863' \
#   -H 'x-wif-timestamp: 1651979576' \
#   -H 'sec-ch-ua-platform: "macOS"' \
#   -H 'Origin: https://bmfw.www.gov.cn' \
#   -H 'Sec-Fetch-Site: same-origin' \
#   -H 'Sec-Fetch-Mode: cors' \
#   -H 'Sec-Fetch-Dest: empty' \
#   -H 'Referer: https://bmfw.www.gov.cn/yqfxdjcx/risk.html' \
#   -H 'Accept-Language: zh-CN,zh;q=0.9' \
#   -H 'Cookie: wdcid=7fb13fcb9e6ed27e; wdlast=1651979546; wdses=2dfab4378afd4485; _gscu_1088464070=5197954504p01620; _gscbrs_1088464070=1; _gscs_1088464070=5197954507mj9e20|pv:1; __asc=508b9938180a1a76c620e6057ee; __auc=508b9938180a1a76c620e6057ee; acw_tc=2760823516519795460733012efcd0a37321bcedd6c467e32cad15d7a583ee; SERVERID=84feac997b1ef24968b27a2eb9d1ae91|1651979561|1651979546' \
#   --data-raw '{"appId":"NcApplication","paasHeader":"zdww","timestampHeader":"1651979576","nonceHeader":"123456789abcdefg","signatureHeader":"97C54AEFD7C1662DF70A7561B42791CD40C108414381EC7E14A08D7D1568EF5B","key":"3C502C97ABDA40D0A60FBEE50FAAD1DA"}' \
#   --compressed

header = {
    'Connection': 'keep-alive',
    'sec-ch-ua': '"Not A;Brand";v="99", "Chromium";v="98", "Google Chrome";v="98"',
    'x-wif-nonce': 'QkjjtiLM2dCratiA',
    'sec-ch-ua-mobile': '?0',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.109 Safari/537.36',
    'x-wif-paasid': 'smt-application',
    'Content-Type': 'application/json; charset=UTF-8',
    'Accept': 'application/json, text/javascript, */*; q=0.01',
    #    'x-wif-signature':'18460600D7C9E7A49AF6A232F2D6474B19F5AA9D23C4731B7551762B75E6E335' ,
    #    'x-wif-timestamp':'1651373901' ,
    'sec-ch-ua-platform': 'macOS',
    'Origin': 'http://bmfw.www.gov.cn',
    'Sec-Fetch-Site': 'cross-site',
    'Sec-Fetch-Mode': 'cors',
    'Sec-Fetch-Dest': 'empty',
    'Referer': 'https://bmfw.www.gov.cn/yqfxdjcx/risk.html',
    'Accept-Language': 'zh-CN,zh;q=0.9',
    'Host': 'bmfw.www.gov.cn'
}


def get_256(s):
    hsobj = hashlib.sha256()
    hsobj.update(s.encode('utf-8'))
    return hsobj.hexdigest().upper()


# o = CryptoJS.SHA256(n + "fTN2pfuisxTavbTuYVSsNJHetwq5bJvCQkjjtiLM2dCratiA" + n)
def get_x_wif_signature(timestamp):
    s = str(timestamp) + signKey + str(timestamp)
    return get_256(s)


def getbody():

    print(timestamp)
    headers = deepcopy(header)

    headers[x_wif_timestamp] = str(timestamp)
    headers[x_wif_signature] = get_x_wif_signature(timestamp)
    x = timestamp + i + nonceHeader + timestamp
    print('token:', x)
    print('signature:', headers[x_wif_signature])
    s = "zdww"
    body = {
        "appId": "NcApplication",
        "paasHeader": passHeader,
        "timestampHeader": timestamp,
        "nonceHeader": nonceHeader,
        "signatureHeader": get_256(x),
        "key": "3C502C97ABDA40D0A60FBEE50FAAD1DA",
    }
    return body, headers


def send_post_request(url):
    body, headers = getbody()
    print('body:', body)
    print('header:', header)
    r = requests.post(url, json=body, headers=headers)
    if r.status_code != 200:
        print('status_code:%s' % r.status_code)
        return
    res = r.json()
    print(res)


send_post_request(url)

# var i = s(t),
#                 n = JSON.parse(i)
#                 .timestampHeader,
#                 o = CryptoJS.SHA256(n + "fTN2pfuisxTavbTuYVSsNJHetwq5bJvCQkjjtiLM2dCratiA" + n)
#                 .toString(CryptoJS.enc.Hex)
#                 .toUpperCase();
#             return $.ajax(Object.assign({
#                     headers: {
#                         "x-wif-nonce": "QkjjtiLM2dCratiA",
#                         "x-wif-paasid": "smt-application",
#                         "x-wif-signature": o,
#                         "x-wif-timestamp": n
#                     },
#                     url: "https://bmfw.www.gov.cn/bjww/interface/interfaceJson",
#                     type: "POST",
#                     dataType: "json",
#                     contentType: "application/json; charset=utf-8",
#                     crossDomain: !0 === !document.all,
#                     data: i
#                 }

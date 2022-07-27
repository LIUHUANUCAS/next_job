curl 'https://bmfw.www.gov.cn/bjww/interface/interfaceJson' \
  -H 'Connection: keep-alive' \
  -H 'sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="98", "Google Chrome";v="98"' \
  -H 'x-wif-nonce: QkjjtiLM2dCratiA' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.109 Safari/537.36' \
  -H 'x-wif-paasid: smt-application' \
  -H 'Content-Type: application/json; charset=UTF-8' \
  -H 'Accept: application/json, text/javascript, */*; q=0.01' \
  -H 'x-wif-signature: 854227256F049141796B5085B8DA8A913F5EC3A6F54EFB465EDA564517D487D1' \
  -H 'x-wif-timestamp: 1651106887' \
  -H 'sec-ch-ua-platform: "macOS"' \
  -H 'Origin: http://bmfw.www.gov.cn' \
  -H 'Sec-Fetch-Site: cross-site' \
  -H 'Sec-Fetch-Mode: cors' \
  -H 'Sec-Fetch-Dest: empty' \
  -H 'Referer: http://bmfw.www.gov.cn/' \
  -H 'Accept-Language: zh-CN,zh;q=0.9' \
  --data-raw '{"appId":"NcApplication","paasHeader":"zdww","timestampHeader":"1651106887","nonceHeader":"123456789abcdefg","signatureHeader":"419937AE88F15320C29DF8EBEDC677C5945A4BABEE4B5753E6D96C241C2E5F80","key":"3C502C97ABDA40D0A60FBEE50FAAD1DA"}' \
  --compressed



curl -X POST 'https://bmfw.www.gov.cn/bjww/interface/interfaceJson' \
  -H 'Connection: keep-alive' \
  -H 'sec-ch-ua: " Not A;Brand";v="99", "Chromium";v="98", "Google Chrome";v="98"' \
  -H 'x-wif-nonce: QkjjtiLM2dCratiA' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.109 Safari/537.36' \
  -H 'x-wif-paasid: smt-application' \
  -H 'Content-Type: application/json; charset=UTF-8' \
  -H 'Accept: application/json, text/javascript, */*; q=0.01' \
  -H 'x-wif-signature: A1D4052DE59B59516FF0A3B668D30E7C08EA7EB41D1259D3BBCC8669ADADB325' \
  -H 'x-wif-timestamp: 1651114635' \
  -H 'sec-ch-ua-platform: "macOS"' \
  -H 'Origin: http://bmfw.www.gov.cn' \
  -H 'Sec-Fetch-Site: cross-site' \
  -H 'Sec-Fetch-Mode: cors' \
  -H 'Sec-Fetch-Dest: empty' \
  -H 'Referer: http://bmfw.www.gov.cn/' \
  -H 'Accept-Language: zh-CN,zh;q=0.9' \
  --data-raw '{"appId": "NcApplication", "paasHeader": "zzdw", "timestampHeader": "1651114635", "nonceHeader": "123456789abcdefg", "signatureHeader": "77A997334B3C56E0FA40F12FE414ADB45C436C42CBA2F3379498750946090419", "key": "3C502C97ABDA40D0A60FBEE50FAAD1DA"}' \
  --compressed








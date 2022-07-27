-- update 2022-07-23-10_new_risk_loc.txt
delete from risk where qhdm = '150800'; -- 内蒙古自治区-巴彦淖尔市-中
delete from risk where qhdm = '371300'; -- 山东省-临沂市-中
delete from risk where qhdm = '410100'; -- 河南省-郑州市-高
delete from risk where qhdm = '440900'; -- 广东省-茂名市-中
delete from risk where qhdm = '441800'; -- 广东省-清远市-中
delete from risk where qhdm = '442000'; -- 广东省-中山市-中
--,nosql,110000,2,北京市,,2022-07-22 09:30:00,none,2
--,nosql,120000,2,天津市,,2022-07-22 09:30:00,none,2
--,nosql,210600,2,辽宁省,丹东市,2022-07-22 09:30:00,none,2
--,nosql,220100,2,吉林省,长春市,2022-07-22 09:30:00,none,2
--,nosql,310000,2,上海市,,2022-07-22 09:30:00,none,2
--,nosql,320700,1,江苏省,连云港市,2022-07-22 09:30:00,none,1
--,nosql,340300,2,安徽省,蚌埠市,2022-07-22 09:30:00,none,2
--,nosql,341300,2,安徽省,宿州市,2022-07-22 09:30:00,none,2
--,nosql,341600,2,安徽省,亳州市,2022-07-22 09:30:00,none,2
--,nosql,360100,2,江西省,南昌市,2022-07-22 09:30:00,none,2
--,nosql,410400,2,河南省,平顶山市,2022-07-22 09:30:00,none,2
--,nosql,411500,2,河南省,信阳市,2022-07-22 09:30:00,none,2
--,nosql,411700,2,河南省,驻马店市,2022-07-22 09:30:00,none,2
--,nosql,440300,2,广东省,深圳市,2022-07-22 09:30:00,none,2
--,nosql,440400,2,广东省,珠海市,2022-07-22 09:30:00,none,2
--,nosql,440600,2,广东省,佛山市,2022-07-22 09:30:00,none,2
--,nosql,441300,2,广东省,惠州市,2022-07-22 09:30:00,none,2
--,nosql,450500,2,广西壮族自治区,北海市,2022-07-22 09:30:00,none,2
--,nosql,500000,2,重庆市,,2022-07-22 09:30:00,none,2
--,nosql,510100,2,四川省,成都市,2022-07-22 09:30:00,none,2
--,nosql,511400,2,四川省,眉山市,2022-07-22 09:30:00,none,2
--,nosql,620100,2,甘肃省,兰州市,2022-07-22 09:30:00,none,2
--,nosql,620400,2,甘肃省,白银市,2022-07-22 09:30:00,none,2
--,nosql,620500,2,甘肃省,天水市,2022-07-22 09:30:00,none,2
--,nosql,620600,2,甘肃省,武威市,2022-07-22 09:30:00,none,2
--,nosql,620700,1,甘肃省,张掖市,2022-07-22 09:30:00,none,1
--,nosql,621100,2,甘肃省,定西市,2022-07-22 09:30:00,none,2
--,nosql,621200,2,甘肃省,陇南市,2022-07-22 09:30:00,none,2
--,nosql,622900,2,甘肃省,临夏回族自治州,2022-07-22 09:30:00,none,2
--,nosql,623000,2,甘肃省,甘南藏族自治州,2022-07-22 09:30:00,none,2
----------更新记录----------
/***

1.删除记录:
	1) 内蒙古自治区巴彦淖尔市由中风险降为低风险
	2) 山东省临沂市由中风险降为低风险
	3) 河南省郑州市由高风险降为低风险
	4) 广东省茂名市由中风险降为低风险
	5) 广东省清远市由中风险降为低风险
	6) 广东省中山市由中风险降为低风险
2.无需更新:
	1) 北京市由高风险保持为高风险
	2) 天津市由高风险保持为高风险
	3) 辽宁省丹东市由高风险保持为高风险
	4) 吉林省长春市由高风险保持为高风险
	5) 上海市由高风险保持为高风险
	6) 江苏省连云港市由中风险保持为中风险
	7) 安徽省蚌埠市由高风险保持为高风险
	8) 安徽省宿州市由高风险保持为高风险
	9) 安徽省亳州市由高风险保持为高风险
	10) 江西省南昌市由高风险保持为高风险
	11) 河南省平顶山市由高风险保持为高风险
	12) 河南省信阳市由高风险保持为高风险
	13) 河南省驻马店市由高风险保持为高风险
	14) 广东省深圳市由高风险保持为高风险
	15) 广东省珠海市由高风险保持为高风险
	16) 广东省佛山市由高风险保持为高风险
	17) 广东省惠州市由高风险保持为高风险
	18) 广西壮族自治区北海市由高风险保持为高风险
	19) 重庆市由高风险保持为高风险
	20) 四川省成都市由高风险保持为高风险
	21) 四川省眉山市由高风险保持为高风险
	22) 甘肃省兰州市由高风险保持为高风险
	23) 甘肃省白银市由高风险保持为高风险
	24) 甘肃省天水市由高风险保持为高风险
	25) 甘肃省武威市由高风险保持为高风险
	26) 甘肃省张掖市由中风险保持为中风险
	27) 甘肃省定西市由高风险保持为高风险
	28) 甘肃省陇南市由高风险保持为高风险
	29) 甘肃省临夏回族自治州由高风险保持为高风险
	30) 甘肃省甘南藏族自治州由高风险保持为高风险
**/


-- update 2022-07-17-10_new_risk_loc.txt
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('220100','2','吉林省','长春市','2022-07-17 11:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('340300','2','安徽省','蚌埠市','2022-07-17 11:00:00','高');
delete from risk where qhdm = '110000'; -- 北京市--中
delete from risk where qhdm = '320300'; -- 江苏省-徐州市-中
--,nosql,120000,1,天津市,,2022-07-16 12:00:00,none,1
--,nosql,150800,2,内蒙古自治区,巴彦淖尔市,2022-07-16 12:00:00,none,2
--,nosql,310000,2,上海市,,2022-07-16 12:00:00,none,2
--,nosql,320200,2,江苏省,无锡市,2022-07-16 12:00:00,none,2
--,nosql,320700,2,江苏省,连云港市,2022-07-16 12:00:00,none,2
--,nosql,350600,1,福建省,漳州市,2022-07-16 12:00:00,none,1
--,nosql,350900,2,福建省,宁德市,2022-07-16 12:00:00,none,2
--,nosql,360100,2,江西省,南昌市,2022-07-16 12:00:00,none,2
--,nosql,370200,1,山东省,青岛市,2022-07-16 12:00:00,none,1
--,nosql,371300,2,山东省,临沂市,2022-07-16 12:00:00,none,2
--,nosql,410100,2,河南省,郑州市,2022-07-16 12:00:00,none,2
--,nosql,410400,2,河南省,平顶山市,2022-07-16 12:00:00,none,2
--,nosql,411300,2,河南省,南阳市,2022-07-16 12:00:00,none,2
--,nosql,411700,2,河南省,驻马店市,2022-07-16 12:00:00,none,2
--,nosql,440100,2,广东省,广州市,2022-07-16 12:00:00,none,2
--,nosql,440200,2,广东省,韶关市,2022-07-16 12:00:00,none,2
--,nosql,440300,2,广东省,深圳市,2022-07-16 12:00:00,none,2
--,nosql,440400,2,广东省,珠海市,2022-07-16 12:00:00,none,2
--,nosql,440600,2,广东省,佛山市,2022-07-16 12:00:00,none,2
--,nosql,440700,1,广东省,江门市,2022-07-16 12:00:00,none,1
--,nosql,440900,2,广东省,茂名市,2022-07-16 12:00:00,none,2
--,nosql,441800,2,广东省,清远市,2022-07-16 12:00:00,none,2
--,nosql,441900,2,广东省,东莞市,2022-07-16 12:00:00,none,2
--,nosql,442000,2,广东省,中山市,2022-07-16 12:00:00,none,2
--,nosql,450500,2,广西壮族自治区,北海市,2022-07-16 12:00:00,none,2
--,nosql,460100,2,海南省,海口市,2022-07-16 12:00:00,none,2
--,nosql,510100,2,四川省,成都市,2022-07-16 12:00:00,none,2
--,nosql,610100,1,陕西省,西安市,2022-07-16 12:00:00,none,1
--,nosql,620100,2,甘肃省,兰州市,2022-07-16 12:00:00,none,2
--,nosql,620400,2,甘肃省,白银市,2022-07-16 12:00:00,none,2
--,nosql,620500,2,甘肃省,天水市,2022-07-16 12:00:00,none,2
--,nosql,620700,2,甘肃省,张掖市,2022-07-16 12:00:00,none,2
--,nosql,621100,2,甘肃省,定西市,2022-07-16 12:00:00,none,2
--,nosql,621200,2,甘肃省,陇南市,2022-07-16 12:00:00,none,2
--,nosql,622900,2,甘肃省,临夏回族自治州,2022-07-16 12:00:00,none,2
--,nosql,623000,2,甘肃省,甘南藏族自治州,2022-07-16 12:00:00,none,2
update risk set risk = '1' where qhdm = '341300'; -- 安徽省-宿州市-高->中
update risk set risk = '1' where qhdm = '440800'; -- 广东省-湛江市-高->中
update risk set risk = '1' where qhdm = '441700'; -- 广东省-阳江市-高->中
----------更新记录----------
/***

1.添加记录:
	1) 吉林省长春市升为高风险
	2) 安徽省蚌埠市升为高风险
2.删除记录:
	1) 北京市由中风险降为低风险
	2) 江苏省徐州市由中风险降为低风险
3.无需更新:
	1) 天津市由中风险保持为中风险
	2) 内蒙古自治区巴彦淖尔市由高风险保持为高风险
	3) 上海市由高风险保持为高风险
	4) 江苏省无锡市由高风险保持为高风险
	5) 江苏省连云港市由高风险保持为高风险
	6) 福建省漳州市由中风险保持为中风险
	7) 福建省宁德市由高风险保持为高风险
	8) 江西省南昌市由高风险保持为高风险
	9) 山东省青岛市由中风险保持为中风险
	10) 山东省临沂市由高风险保持为高风险
	11) 河南省郑州市由高风险保持为高风险
	12) 河南省平顶山市由高风险保持为高风险
	13) 河南省南阳市由高风险保持为高风险
	14) 河南省驻马店市由高风险保持为高风险
	15) 广东省广州市由高风险保持为高风险
	16) 广东省韶关市由高风险保持为高风险
	17) 广东省深圳市由高风险保持为高风险
	18) 广东省珠海市由高风险保持为高风险
	19) 广东省佛山市由高风险保持为高风险
	20) 广东省江门市由中风险保持为中风险
	21) 广东省茂名市由高风险保持为高风险
	22) 广东省清远市由高风险保持为高风险
	23) 广东省东莞市由高风险保持为高风险
	24) 广东省中山市由高风险保持为高风险
	25) 广西壮族自治区北海市由高风险保持为高风险
	26) 海南省海口市由高风险保持为高风险
	27) 四川省成都市由高风险保持为高风险
	28) 陕西省西安市由中风险保持为中风险
	29) 甘肃省兰州市由高风险保持为高风险
	30) 甘肃省白银市由高风险保持为高风险
	31) 甘肃省天水市由高风险保持为高风险
	32) 甘肃省张掖市由高风险保持为高风险
	33) 甘肃省定西市由高风险保持为高风险
	34) 甘肃省陇南市由高风险保持为高风险
	35) 甘肃省临夏回族自治州由高风险保持为高风险
	36) 甘肃省甘南藏族自治州由高风险保持为高风险
4.更新记录:
	1) 安徽省宿州市由高风险降为中风险
	2) 广东省湛江市由高风险降为中风险
	3) 广东省阳江市由高风险降为中风险
**/

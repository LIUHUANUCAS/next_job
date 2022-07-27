-- update 2022-07-11-08_new_risk_loc.txt
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('320700','2','江苏省','连云港市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('360100','2','江西省','南昌市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('440200','2','广东省','韶关市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('440600','2','广东省','佛山市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('440700','2','广东省','江门市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('440800','2','广东省','湛江市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('440900','2','广东省','茂名市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('441700','2','广东省','阳江市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('441900','2','广东省','东莞市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('442000','2','广东省','中山市','2022-07-11 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('620400','2','甘肃省','白银市','2022-07-11 09:00:00','高');
--,nosql,110000,2,北京市,,2022-07-10 09:30:00,none,2
--,nosql,120000,2,天津市,,2022-07-10 09:30:00,none,2
--,nosql,150800,2,内蒙古自治区,巴彦淖尔市,2022-07-10 09:30:00,none,2
--,nosql,310000,2,上海市,,2022-07-10 09:30:00,none,2
--,nosql,320200,2,江苏省,无锡市,2022-07-10 09:30:00,none,2
--,nosql,320300,2,江苏省,徐州市,2022-07-10 09:30:00,none,2
--,nosql,341300,2,安徽省,宿州市,2022-07-10 09:30:00,none,2
--,nosql,350600,2,福建省,漳州市,2022-07-10 09:30:00,none,2
--,nosql,350900,2,福建省,宁德市,2022-07-10 09:30:00,none,2
--,nosql,370200,2,山东省,青岛市,2022-07-10 09:30:00,none,2
--,nosql,371300,2,山东省,临沂市,2022-07-10 09:30:00,none,2
--,nosql,411700,2,河南省,驻马店市,2022-07-10 09:30:00,none,2
--,nosql,440100,2,广东省,广州市,2022-07-10 09:30:00,none,2
--,nosql,440300,2,广东省,深圳市,2022-07-10 09:30:00,none,2
--,nosql,460100,2,海南省,海口市,2022-07-10 09:30:00,none,2
--,nosql,610100,2,陕西省,西安市,2022-07-10 09:30:00,none,2
--,nosql,620100,2,甘肃省,兰州市,2022-07-10 09:30:00,none,2
update risk set risk = '1' where qhdm = '210200'; -- 辽宁省-大连市-高->中
update risk set risk = '1' where qhdm = '210600'; -- 辽宁省-丹东市-高->中
----------更新记录----------
/***

1.添加记录:
	1) 江苏省连云港市升为高风险
	2) 江西省南昌市升为高风险
	3) 广东省韶关市升为高风险
	4) 广东省佛山市升为高风险
	5) 广东省江门市升为高风险
	6) 广东省湛江市升为高风险
	7) 广东省茂名市升为高风险
	8) 广东省阳江市升为高风险
	9) 广东省东莞市升为高风险
	10) 广东省中山市升为高风险
	11) 甘肃省白银市升为高风险
2.无需更新:
	1) 北京市由高风险保持为高风险
	2) 天津市由高风险保持为高风险
	3) 内蒙古自治区巴彦淖尔市由高风险保持为高风险
	4) 上海市由高风险保持为高风险
	5) 江苏省无锡市由高风险保持为高风险
	6) 江苏省徐州市由高风险保持为高风险
	7) 安徽省宿州市由高风险保持为高风险
	8) 福建省漳州市由高风险保持为高风险
	9) 福建省宁德市由高风险保持为高风险
	10) 山东省青岛市由高风险保持为高风险
	11) 山东省临沂市由高风险保持为高风险
	12) 河南省驻马店市由高风险保持为高风险
	13) 广东省广州市由高风险保持为高风险
	14) 广东省深圳市由高风险保持为高风险
	15) 海南省海口市由高风险保持为高风险
	16) 陕西省西安市由高风险保持为高风险
	17) 甘肃省兰州市由高风险保持为高风险
3.更新记录:
	1) 辽宁省大连市由高风险降为中风险
	2) 辽宁省丹东市由高风险降为中风险
**/


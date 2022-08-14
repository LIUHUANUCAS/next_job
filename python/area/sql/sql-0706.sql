-- update 2022-07-06-08_new_risk_loc.txt
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('120000','2','天津市','','2022-07-06 09:00:00','高');
insert into risk(qhdm,risk,sfmc,dsmc,rksj,riskmc) values('350900','2','福建省','宁德市','2022-07-06 09:00:00','高');
delete from risk where qhdm = '320100'; -- 江苏省-南京市-中
--,nosql,110000,2,北京市,,2022-07-05 09:30:00,none,2
--,nosql,210200,2,辽宁省,大连市,2022-07-05 09:30:00,none,2
--,nosql,210600,2,辽宁省,丹东市,2022-07-05 09:30:00,none,2
--,nosql,310000,2,上海市,,2022-07-05 09:30:00,none,2
--,nosql,320200,2,江苏省,无锡市,2022-07-05 09:30:00,none,2
--,nosql,320300,2,江苏省,徐州市,2022-07-05 09:30:00,none,2
--,nosql,341300,2,安徽省,宿州市,2022-07-05 09:30:00,none,2
--,nosql,610100,2,陕西省,西安市,2022-07-05 09:30:00,none,2
----------更新记录----------
/***

1.添加记录:
	1) 天津市升为高风险
	2) 福建省宁德市升为高风险
2.删除记录:
	1) 江苏省南京市由中风险降为低风险
3.无需更新:
	1) 北京市由高风险保持为高风险
	2) 辽宁省大连市由高风险保持为高风险
	3) 辽宁省丹东市由高风险保持为高风险
	4) 上海市由高风险保持为高风险
	5) 江苏省无锡市由高风险保持为高风险
	6) 江苏省徐州市由高风险保持为高风险
	7) 安徽省宿州市由高风险保持为高风险
	8) 陕西省西安市由高风险保持为高风险
**/

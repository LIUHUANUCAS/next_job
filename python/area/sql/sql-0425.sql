-- update 2022-04-25_new_risk_loc.txt
insert into risk(qhdm ,risk, sfmc , dsmc , gxsj) values('110000','2','北京市','','2022-04-25 09:02:13');
insert into risk(qhdm ,risk, sfmc , dsmc , gxsj) values('130200','1','河北省','唐山市','2022-04-25 09:02:13');
delete from risk where qhdm = '341500'; -- 安徽省-六安市-中
delete from risk where qhdm = '360100'; -- 江西省-南昌市-中
--,nosql,1,邯郸市,2022-04-24 09:16:04,130400,河北省,none,1
--,nosql,1,邢台市,2022-04-24 09:16:04,130500,河北省,none,1
--,nosql,1,太原市,2022-04-24 09:16:04,140100,山西省,none,1
--,nosql,1,呼伦贝尔市,2022-04-24 09:16:04,150700,内蒙古自治区,none,1
--,nosql,2,长春市,2022-04-24 09:16:04,220100,吉林省,none,2
--,nosql,1,吉林市,2022-04-24 09:16:04,220200,吉林省,none,1
--,nosql,1,白城市,2022-04-24 09:16:04,220800,吉林省,none,1
--,nosql,2,哈尔滨市,2022-04-24 09:16:04,230100,黑龙江省,none,2
--,nosql,1,牡丹江市,2022-04-24 09:16:04,231000,黑龙江省,none,1
--,nosql,1,,2022-04-24 09:16:04,310000,上海市,none,1
--,nosql,1,徐州市,2022-04-24 09:16:04,320300,江苏省,none,1
--,nosql,1,苏州市,2022-04-24 09:16:04,320500,江苏省,none,1
--,nosql,2,宁德市,2022-04-24 09:16:04,350900,福建省,none,2
--,nosql,1,漯河市,2022-04-24 09:16:04,411100,河南省,none,1
--,nosql,1,邵阳市,2022-04-24 09:16:04,430500,湖南省,none,1
--,nosql,1,西安市,2022-04-24 09:16:04,610100,陕西省,none,1
----------更新记录----------
/***

1.添加记录:
	1) 北京市升为高风险
	2) 河北省唐山市升为中风险
2.删除记录:
	1) 安徽省六安市由中风险降为低风险
	2) 江西省南昌市由中风险降为低风险
3.无需更新:
	1) 河北省邯郸市由中风险保持为中风险
	2) 河北省邢台市由中风险保持为中风险
	3) 山西省太原市由中风险保持为中风险
	4) 内蒙古自治区呼伦贝尔市由中风险保持为中风险
	5) 吉林省长春市由高风险保持为高风险
	6) 吉林省吉林市由中风险保持为中风险
	7) 吉林省白城市由中风险保持为中风险
	8) 黑龙江省哈尔滨市由高风险保持为高风险
	9) 黑龙江省牡丹江市由中风险保持为中风险
	10) 上海市由中风险保持为中风险
	11) 江苏省徐州市由中风险保持为中风险
	12) 江苏省苏州市由中风险保持为中风险
	13) 福建省宁德市由高风险保持为高风险
	14) 河南省漯河市由中风险保持为中风险
	15) 湖南省邵阳市由中风险保持为中风险
	16) 陕西省西安市由中风险保持为中风险
**/

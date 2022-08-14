-- update 2022-05-06-08_new_risk_loc.txt
--,nosql,2,,2022-05-05 08:32:39,110000,北京市,none,2
--,nosql,1,邢台市,2022-05-05 08:32:39,130500,河北省,none,1
--,nosql,1,呼伦贝尔市,2022-05-05 08:32:39,150700,内蒙古自治区,none,1
--,nosql,1,丹东市,2022-05-05 08:32:39,210600,辽宁省,none,1
--,nosql,1,营口市,2022-05-05 08:32:39,210800,辽宁省,none,1
--,nosql,1,白城市,2022-05-05 08:32:39,220800,吉林省,none,1
--,nosql,2,哈尔滨市,2022-05-05 08:32:39,230100,黑龙江省,none,2
--,nosql,1,牡丹江市,2022-05-05 08:32:39,231000,黑龙江省,none,1
--,nosql,1,,2022-05-05 08:32:39,310000,上海市,none,1
--,nosql,1,徐州市,2022-05-05 08:32:39,320300,江苏省,none,1
--,nosql,1,信阳市,2022-05-05 08:32:39,411500,河南省,none,1
--,nosql,1,邵阳市,2022-05-05 08:32:39,430500,湖南省,none,1
delete from risk where qhdm = '130200'; -- 河北省-唐山市-中
delete from risk where qhdm = '320500'; -- 江苏省-苏州市-中
delete from risk where qhdm = '370600'; -- 山东省-烟台市-中
----------更新记录----------
/***

1.无需更新:
	1) 北京市由高风险保持为高风险
	2) 河北省邢台市由中风险保持为中风险
	3) 内蒙古自治区呼伦贝尔市由中风险保持为中风险
	4) 辽宁省丹东市由中风险保持为中风险
	5) 辽宁省营口市由中风险保持为中风险
	6) 吉林省白城市由中风险保持为中风险
	7) 黑龙江省哈尔滨市由高风险保持为高风险
	8) 黑龙江省牡丹江市由中风险保持为中风险
	9) 上海市由中风险保持为中风险
	10) 江苏省徐州市由中风险保持为中风险
	11) 河南省信阳市由中风险保持为中风险
	12) 湖南省邵阳市由中风险保持为中风险
2.删除记录:
	1) 河北省唐山市由中风险降为低风险
	2) 江苏省苏州市由中风险降为低风险
	3) 山东省烟台市由中风险降为低风险
**/

-- update 2022-04-23_new.txt
insert into risk(qhdm ,risk, sfmc , dsmc , gxsj) values('130500','1','河北省','邢台市','2022-04-23');
insert into risk(qhdm ,risk, sfmc , dsmc , gxsj) values('220800','1','吉林省','白城市','2022-04-23');
insert into risk(qhdm ,risk, sfmc , dsmc , gxsj) values('320500','1','江苏省','苏州市','2022-04-23');
insert into risk(qhdm ,risk, sfmc , dsmc , gxsj) values('430500','1','湖南省','邵阳市','2022-04-23');
delete from risk where qhdm = '110000'; -- 北京市--高
delete from risk where qhdm = '210800'; -- 辽宁省-营口市-高
delete from risk where qhdm = '230800'; -- 黑龙江省-佳木斯市-中
delete from risk where qhdm = '340400'; -- 安徽省-淮南市-中
delete from risk where qhdm = '341200'; -- 安徽省-阜阳市-中
delete from risk where qhdm = '350500'; -- 福建省-泉州市-中
delete from risk where qhdm = '371000'; -- 山东省-威海市-中
delete from risk where qhdm = '411400'; -- 河南省-商丘市-中
delete from risk where qhdm = '411600'; -- 河南省-周口市-中
delete from risk where qhdm = '440100'; -- 广东省-广州市-中
--,nosql,1,邯郸市,2022/4/19 10:30,130400,河北省,none,1
--,nosql,1,太原市,2022/4/19 10:30,140100,山西省,none,1
--,nosql,2,长春市,2022/4/19 10:30,220100,吉林省,none,2
--,nosql,1,吉林市,2022/4/19 10:30,220200,吉林省,none,1
--,nosql,1,牡丹江市,2022/4/19 10:30,231000,黑龙江省,none,1
--,nosql,1,,2022/4/19 10:30,310000,上海市,none,1
--,nosql,1,徐州市,2022/4/19 10:30,320300,江苏省,none,1
--,nosql,1,六安市,2022/4/19 10:30,341500,安徽省,none,1
--,nosql,2,宁德市,2022/4/19 10:30,350900,福建省,none,2
--,nosql,1,南昌市,2022/4/19 10:30,360100,江西省,none,1
--,nosql,1,漯河市,2022/4/19 10:30,411100,河南省,none,1
--,nosql,1,西安市,2022/4/19 10:30,610100,陕西省,none,1
update risk set risk = '2' where qhdm = '230100'; -- 黑龙江省-哈尔滨市-中->高
----------更新记录----------
/***

1.添加记录:
	1) 河北省邢台市升为中风险
	2) 吉林省白城市升为中风险
	3) 江苏省苏州市升为中风险
	4) 湖南省邵阳市升为中风险
2.删除记录:
	1) 北京市由高风险降为低风险
	2) 辽宁省营口市由高风险降为低风险
	3) 黑龙江省佳木斯市由中风险降为低风险
	4) 安徽省淮南市由中风险降为低风险
	5) 安徽省阜阳市由中风险降为低风险
	6) 福建省泉州市由中风险降为低风险
	7) 山东省威海市由中风险降为低风险
	8) 河南省商丘市由中风险降为低风险
	9) 河南省周口市由中风险降为低风险
	10) 广东省广州市由中风险降为低风险
3.无需更新:
	1) 河北省邯郸市由中风险保持为中风险
	2) 山西省太原市由中风险保持为中风险
	3) 吉林省长春市由高风险保持为高风险
	4) 吉林省吉林市由中风险保持为中风险
	5) 黑龙江省牡丹江市由中风险保持为中风险
	6) 上海市由中风险保持为中风险
	7) 江苏省徐州市由中风险保持为中风险
	8) 安徽省六安市由中风险保持为中风险
	9) 福建省宁德市由高风险保持为高风险
	10) 江西省南昌市由中风险保持为中风险
	11) 河南省漯河市由中风险保持为中风险
	12) 陕西省西安市由中风险保持为中风险
4.更新记录:
	1) 黑龙江省哈尔滨市由中风险升为高风险
**/

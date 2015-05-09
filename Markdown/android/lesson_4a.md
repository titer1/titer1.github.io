#sql lesson
```
4a-15课开始，之前主要是基础 activity life cycle
```
![](sql_overview.jpg)
sql表长得像这样
![](4a_15_sql_tbl.jpg)

- select * from weather where data = blalla
- select * from weather order by max DESC LIMIT 1 //have a try

- more sql operation
	- delete rows
	- update rows
	- insert rows
	- add columns

- more sql API in android
  得到类似urlbuilder的简单使用效果
  
  ![](4a_17_sql.jpg)
- more about data stroage

#overview arch 
```
lesson 4a 18
```
![](4a_18_overview.jpg)

##intro to weather contract

![](4a_19_weather_contact.jpg)

##又见solution weather table colums solutions

![](04_21_weather_sql_tbl.jpg)

## inner join 2 tables
![](4a_22_iner_Join.jpg)

##休息时间
don 请新学者 深入学习下 foreign key 和joins的要点(in lesson 4a-23 )
![](3a_24_foreign_key.jpg)

## our weather contact
![](4a_25_contract.jpg)

##实践..代码时间  weatherContract.java
![](4a_25_codes.jpg)
don详细展示了key/foreign key

###define constants in contract

![](4a_26_todo_addConstant.jpg)

### locationEntry
![](4a_27_anotherEntry_locationEntry.jpg)

##第二章节 sqllite open helper and sunshine database 反复

###下一站 地图 开始移动啦
![](4a_28_target_sqlHelper.jpg)
### weatherDbHelper 代码
![](4a_28_weatherDbhelper_1.jpg)
- 数据库名字
![](4a_28_weatherDbhelper_onCreate.jpg)
- 数据库的相关语句
	- create table
	- 指定外键

###数据库测试
![](4a_28_make_use_test_case_find_not_create_tbl.jpg)
结果是没有通过。
大致原因是 只创建了 weather.db,还没有创建 locatin.db
### next to modify
![](4a_29_fix.jpg)

下面就是来弥补剩下的一个 db了，
### create sunshine location DB solution
![](4a_30_code_location_db.jpg)

###sqlite open helper on Upgrade 
数据库升级啦
![](4a_31_onUPgrade.jpg)
- 必须手动改变数据库版本号？
- 数据库变化
	- 行变化
	- 列变化
	- 整体结构变化
	
- 什么时候执行？

##第三章节  readwrite from a database
###3.1 overview
![](4a_3a_rw_test.jpg)

###3.2 plan
![](4a_32_testdb_plan.jpg)


![](3_32_get.jpg)

![](3_32_insertdb.jpg)

####3.3 难点 query

![](3_32_query_template.jpg)
![](3_32_query_eg.jpg)

![](3_33_db_checklist.jpg)
####3.4 代码实践 反复 
```
第三章节的代码 集中于此
```
关键就是执行之前的checklist,写出 testLocationTable.
![](4a_34_testDb_final.jpg)

同样的原理用于测试 weathertable.ok ,let go


#end
用了2小时，谢谢don的陪伴
- data storage diagram overview
- activity lifecycle ,旋转屏幕时的变化（pause..restart?)
- database test





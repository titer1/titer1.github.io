#udacity android 学习笔记: lesson 4 part a
-------
作者：干货店打杂的 /titer1 /Archimedes
出处：https://code.csdn.net/titer1
联系：1307316一九六八
声明：本文采用以下协议进行授权： 自由转载-非商用-非衍生-保持署名|[Creative Commons BY-NC-ND 3.0](http://creativecommons.org/licenses/by-nc-nd/3.0/deed.zh) ，转载请注明作者及出处。
tips:https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/

-------
#sql lesson
```
4a-15课开始，之前主要是基础 activity life cycle
```
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/sql_overview.jpg)
sql表长得像这样
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_15_sql_tbl.jpg)

- select * from weather where data = blalla
- select * from weather order by max DESC LIMIT 1 //have a try

- more sql operation
	- delete rows
	- update rows
	- insert rows
	- add columns

- more sql API in android
  得到类似urlbuilder的简单使用效果
  
  ![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_17_sql.jpg)
- more about data stroage

#overview arch 反复
```
lesson 4a 18
```
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_18_overview.jpg)

##intro to weather contract

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_19_weather_contact.jpg)

##又见solution weather table colums solutions

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/04_21_weather_sql_tbl.jpg)

## inner join 2 tables
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_22_iner_Join.jpg)

##休息时间
don 请新学者 深入学习下 foreign key 和joins的要点(in lesson 4a-23 )
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/3a_24_foreign_key.jpg)

## our weather contact
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_25_contract.jpg)

##实践..代码时间  weatherContract.java
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_25_codes.jpg)
don详细展示了key/foreign key

###define constants in contract

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_26_todo_addConstant.jpg)

### locationEntry
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_27_anotherEntry_locationEntry.jpg)

##第二章节 sqllite open helper and sunshine database 反复

###下一站 地图 开始移动啦
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_28_target_sqlHelper.jpg)
### weatherDbHelper 代码
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_28_weatherDbhelper_1.jpg)
- 数据库名字
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_28_weatherDbhelper_onCreate.jpg)
- 数据库的相关语句
	- create table
	- 指定外键

###数据库测试
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_28_make_use_test_case_find_not_create_tbl.jpg)
结果是没有通过。
大致原因是 只创建了 weather.db,还没有创建 locatin.db
### next to modify
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_29_fix.jpg)

下面就是来弥补剩下的一个 db了，
### create sunshine location DB solution
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_30_code_location_db.jpg)

###sqlite open helper on Upgrade 
数据库升级啦
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_31_onUPgrade.jpg)
- 必须手动改变数据库版本号？
- 数据库变化
	- 行变化
	- 列变化
	- 整体结构变化
	
- 什么时候执行？

##第三章节  readwrite from a database
###3.1 overview
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_3a_rw_test.jpg)

###3.2 plan
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_32_testdb_plan.jpg)


![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/3_32_get.jpg)

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/3_32_insertdb.jpg)

####3.3 难点 query

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/3_32_query_template.jpg)
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/3_32_query_eg.jpg)

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/3_33_db_checklist.jpg)
####3.4 代码实践 反复 
```
第三章节的代码 集中于此
```
关键就是执行之前的checklist,写出 testLocationTable.
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/4a_34_testDb_final.jpg)

同样的原理用于测试 weathertable.ok ,let go


#end
用了2小时，谢谢don的陪伴
- data storage diagram overview
- activity lifecycle ,旋转屏幕时的变化（pause..restart?)
- database test





#udacity android 实践笔记: lesson 4 part a
-------
作者：干货店打杂的 /titer1 /Archimedes
出处：https://code.csdn.net/titer1
联系：1307316一九六八(短信最佳)
声明：本文采用以下协议进行授权： 自由转载-非商用-非衍生-保持署名|[Creative Commons BY-NC-ND 3.0](http://creativecommons.org/licenses/by-nc-nd/3.0/deed.zh) ，转载请注明作者及出处。
tips:https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/

-------

```
this is weekend time
last time ,we have learn form the video
and now ,we are run the code directly.
let us go.

thanks jackson
版本变化的
rs232 uart txd rxd clk 115200 10k
usb 
	at least 5 ,传输类型
	1.0 fullspeded <10M
	2.0 highspeedd, 30M？ 720p 20fps
		printer more high than uvc
        usb mass storage ..dirver-inside
	3.0 >100M
	
i2c
	2 line .clk data
    400k bps,命令
    
```
```
是否是 fake data,看看 数据里面 有没有 traped in weather station,就知道当前情况了
```

其他 四大组件

service
broad
content provider
activity

#4.01 life cycle
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/android_application_life_cycle.gif)


![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/c4a_lifeCycle.jpg)
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/c4a_disconect.jpg)
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/c4a_restore.jpg)

```
以上介绍了 声明周期

```
##！！ 动手笔记 生命周期
看activity的生命周期，就是
看 mainActivity的logcat，非常清楚

###操作布凑
进入mainActivity --> detail Activity -->回到 mainActivity

还有 Main Activity --> seting  -->切回

```
为什么能够看到如上的提示，根本原因是有代码logcat，
所有的activity life cycle hanlders
```
#overviw 图
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/c4a_overview.jpg)
- contract
- db builder
- content provider 四大组件之一



#4.02 第四章最基础的代码框架

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/c4a_2_diff.jpg)
- 完整的测试框架
- 添加了 location weather的contract
- 添加了 location weather相关的 sql builder

#4.03 定义 数据库表项 for location 
##contract解释
```
/**
 * Defines table and column names for the weather database.
 */
```
就是定义 表格内容

这里的更新就是 增加了
location table 的列内容定义

#4.04 完善 location database 
- 目标 测试 weather 数据库 创建 /插入 
- 


在数据库初始化代码处，
也就是 weatherDbHelper的位置，
仿照 weather database的创建，
添加以下代码

``` java
public class WeatherDbHelper extends SQLiteOpenHelper {
    static final String DATABASE_NAME = "weather.db";
    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
    
        final String SQL_CREATE_LOCATION_TABLE = "CREATE TABLE " + LocationEntry.TABLE_NAME + " (" +
                LocationEntry._ID + " INTEGER PRIMARY KEY," +
                LocationEntry.COLUMN_LOCATION_SETTING + " TEXT UNIQUE NOT NULL, " +
                LocationEntry.COLUMN_CITY_NAME + " TEXT NOT NULL, " +
                LocationEntry.COLUMN_COORD_LAT + " REAL NOT NULL, " +
                LocationEntry.COLUMN_COORD_LONG + " REAL NOT NULL " +
                " );";
...
        sqLiteDatabase.execSQL(SQL_CREATE_LOCATION_TABLE);//新添加的
        sqLiteDatabase.execSQL(SQL_CREATE_WEATHER_TABLE);

```


###使能数据库创建测试程序 testCreateDb

程序介绍

```
        Students: Uncomment this test once you've written the code to create the Location
        table.  Note that you will have to have chosen the same column names that I did in my solution for this test to compile, so if you haven't yet done that, this is
        a good time to change your column names to match mine.

        Note that this only tests that the Location table has the correct columns, since we
        give you the code for the weather table.  This test does not look at the
 
```


### 使能 test utilites
``` java

    /*
        Students: You can uncomment this helper function once you have finished creating the
        LocationEntry part of the WeatherContract.
     */
    static ContentValues createNorthPoleLocationValues() {
        // Create a new map of values, where column names are the keys
        ContentValues testValues = new ContentValues();
        testValues.put(WeatherContract.LocationEntry.COLUMN_LOCATION_SETTING, TEST_LOCATION);
        testValues.put(WeatherContract.LocationEntry.COLUMN_CITY_NAME, "North Pole");
        testValues.put(WeatherContract.LocationEntry.COLUMN_COORD_LAT, 64.7488);
        testValues.put(WeatherContract.LocationEntry.COLUMN_COORD_LONG, -147.353);

        return testValues;
    }

    /*
        Students: You can uncomment this function once you have finished creating the
        LocationEntry part of the WeatherContract as well as the WeatherDbHelper.
     */
    static long insertNorthPoleLocationValues(Context context) {
        // insert our test records into the database
        WeatherDbHelper dbHelper = new WeatherDbHelper(context);//
        我的认识，这里会创建一个表
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues testValues = TestUtilities.createNorthPoleLocationValues();

        long locationRowId;
        locationRowId = db.insert(WeatherContract.LocationEntry.TABLE_NAME, null, testValues);
//这里将测试表的插入

        // Verify we got a row back.
        assertTrue("Error: Failure to insert North Pole Location Values", locationRowId != -1);

        return locationRowId;
    }
```




上面三处文件更新
#4.05 test Location Table
这里 近一处 更新

可以从 注释里面进一步完善本小节内容 

下面小节的内容将会被充实代码

``` java


  /*
        Students:  Here is where you will build code to test that we can insert and query the location database. 
        We've done a lot of work for you.  You'll want to look in TestUtilitie
        where you can uncomment out the "createNorthPoleLocationValues" function.  You can also make use of the ValidateCurrentRecord function from within TestUtilities.
    */
    public void testLocationTable() {
        // First step: Get reference to writable database

        // Create ContentValues of what you want to insert
        // (you can use the createNorthPoleLocationValues if you wish)

        // Insert ContentValues into database and get a row ID back

        // Query the database and receive a Cursor back

        // Move the cursor to a valid database row

        // Validate data in resulting Cursor with the original ContentValues
        // (you can use the validateCurrentRecord function in TestUtilities to validate the
        // query if you like)

        // Finally, close the cursor and database

    }```

### 6步 测试table(insert/quiery ...)
所有更新的代码在此
``` java
 public void testLocationTable() {

        // First step: Get reference to writable database
        // If there's an error in those massive SQL table creation Strings,
        // errors will be thrown here when you try to get a writable database.
        WeatherDbHelper dbHelper = new WeatherDbHelper(mContext);
        SQLiteDatabase db = dbHelper.getWritableDatabase();

        // Second Step: Create ContentValues of what you want to insert
        // (you can use the createNorthPoleLocationValues if you wish)
        ContentValues testValues = TestUtilities.createNorthPoleLocationValues();

        // Third Step: Insert ContentValues into database and get a row ID back
        long locationRowId;
        locationRowId = db.insert(WeatherContract.LocationEntry.TABLE_NAME, null, testValues);

        // Verify we got a row back.
        assertTrue(locationRowId != -1);

        // Data's inserted.  IN THEORY.  Now pull some out to stare at it and verify it made
        // the round trip.

        // Fourth Step: Query the database and receive a Cursor back
        // A cursor is your primary interface to the query results.
        Cursor cursor = db.query(
                WeatherContract.LocationEntry.TABLE_NAME,  // Table to Query
                null, // all columns
                null, // Columns for the "where" clause
                null, // Values for the "where" clause
                null, // columns to group by
                null, // columns to filter by row groups
                null // sort order
        );

        // Move the cursor to a valid database row and check to see if we got any records back
        // from the query
        assertTrue( "Error: No Records returned from location query", cursor.moveToFirst() );

        // Fifth Step: Validate data in resulting Cursor with the original ContentValues
        // (you can use the validateCurrentRecord function in TestUtilities to validate the
        // query if you like)
        TestUtilities.validateCurrentRecord("Error: Location Query Validation Failed",
                cursor, testValues);

        // Move the cursor to demonstrate that there is only one record in the database
        assertFalse( "Error: More than one record returned from location query",
                cursor.moveToNext() );

        // Sixth Step: Close Cursor and Database
        cursor.close();
        db.close();
    }
```

#!! todo 效果截图 
这处 等待网络 联通后，应该有 具体的效果图展示，
初步看到这里有若干的assert

//运行方法：lesson 4a 28 - SQLiteOpenHelper and Sunshine Database.mp4中

我把 问题的环境 运行方法 已经 整理，待后期更新



#4.06 test weather table
和上面一样，修改的只有 testDb.java

```
编辑器里面 有 主题切换，可以后界面颜色 ，字体，保护眼睛，你懂的

```
- 不仅仅像上面 重新 写了一个 test*****talbe的函数，
- 在testWeatherTalbe程序中，先调用了 testLoactionTalbe的代码，
该代码被封装起来为insertLocation，其实内容就是 testLocationTable

- 函数的返回值是 对应项目 query后的rowid 。

两者衔接的代码如下，
```
        long locationRowId = insertLocation();

        // Second Step (Weather): Create weather values
        ContentValues weatherValues = TestUtilities.createWeatherValues(locationRowId);

		//*.insert
		
		//*.query
       
```

```
至于是否起到 外键的作用，待证明
```


#小憩时间
至此，逻辑正确的话，两个数据表格都测到测试
未来目标是 4.24..还有很多。
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/android/c4a_testdb_over.jpg)
- 给出初步的 创建 weather表的表框架
- 创建 location 表
- 填充 test location 
- 填充 test weather location (insert query ...,调用了 testlocation的结果)


一句话 ，期中 4.06是一个 小的 里程碑




















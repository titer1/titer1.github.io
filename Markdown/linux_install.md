


#install opencv on ubuntu 12.10

```
apt-get  install on shiyanlou 的速度？
apt-source ?
```

```
After this operation, 100 MB of additional disk space will be used.
```


------



##step 1

#### setp 1.1 get opencv source
准备源码 opencv
Opencv的源码,2.4.9,90M左右
百度网盘链接：


或者类似方法
```
wget http://downloads.sourceforge.net/project/opencvlibrary/opencv-unix/2.4.2/OpenCV-2.4.2.tar.bz2

tar xvf OpenCV-2.4.2.tar.bz2
```

### step 1.2 install build-essential
build-essential 软件包，涵盖gcc/g++/gdb/make 
```
    sudo apt-get install build-essential  
```
###step 1.3 install pakcage about multi-media
支持读写图片以及视频等,about 100MB
```
    sudo apt-get install  libgtk2.0-dev libavcodec-dev libavformat-dev  libtiff4-dev  libswscale-dev libjasper-dev  
```
###step 1.4 install cmake
编译，大小10M左右
```
sudo apt-get install cmake
```

### step 1.5 install pkg-config
pkg-config，它是一个提供从源代码中编译软件时查询已安装的库时使用的统一接口的计算机软件。
```
sudo apt-get install pkg-config  
```

#二、编译安装过程

##2.1 环境监测：
   使用cmake来检测编译环境以及生成makefile以及其他project信息，在使用cmake过程可以设置一些参数。

  在本目录下(opencv源码目录)使用cmake，注意后面的点表示在当前目录下寻找CMakeLists.txt。
```
    cmake .  
```
结果简略如下：
```
   ...
-- Configuring done
-- Generating done
-- Build files have been written to: /media/sda_m/opencv-2.4.9
```

##2.2 使用make编译
耗时间20分钟，下一步试试有没有已经编译好的bin文件
```
make  
```
正确编译结果是：
```
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/traincascade.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/cascadeclassifier.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/boost.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/features.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/haarfeatures.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/lbpfeatures.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/HOGfeatures.cpp.o
[100%] Building CXX object apps/traincascade/CMakeFiles/opencv_traincascade.dir/imagestorage.cpp.o
Linking CXX executable ../../bin/opencv_traincascade

```
##2.3 使用make install 安装
```
sudo make install  
```
正确的结果提示是：
```
...
-- Set runtime path of "/usr/local/bin/opencv_haartraining" to "/usr/local/lib"
-- Installing: /usr/local/bin/opencv_createsamples
-- Set runtime path of "/usr/local/bin/opencv_createsamples" to "/usr/local/lib"
-- Installing: /usr/local/bin/opencv_performance
-- Set runtime path of "/usr/local/bin/opencv_performance" to "/usr/local/lib"
-- Installing: /usr/local/bin/opencv_traincascade
-- Set runtime path of "/usr/local/bin/opencv_traincascade" to "/usr/local/lib"

```

##2.4 添加动态库信息
  在文件/etc/ld.so.conf中添加 /usr/local/lib（这个跟安装目录有关， {CMAKE_INSTALL_PREFIX}/lib），
  也可以在/etc/ld.so.conf.d 目录下增加一个conf文件（可以命名为 opencv.conf），同样添加 /usr/local/lib

```
查看已经生成的动态库
root@noya-VirtualBox:/usr/local/lib# ls
libopencv_calib3d.so           libopencv_gpu.so            libopencv_nonfree.so          libopencv_superres.so
libopencv_calib3d.so.2.4       libopencv_gpu.so.2.4        libopencv_nonfree.so.2.4      libopencv_superres.so.2.4
libopencv_calib3d.so.2.4.9     libopencv_gpu.so.2.4.9      libopencv_nonfree.so.2.4.9    libopencv_superres.so.2.4.9
libopencv_contrib.so           libopencv_highgui.so        libopencv_objdetect.so        libopencv_ts.a
libopencv_contrib.so.2.4       libopencv_highgui.so.2.4    libopencv_objdetect.so.2.4    libopencv_video.so
libopencv_contrib.so.2.4.9     libopencv_highgui.so.2.4.9  libopencv_objdetect.so.2.4.9  libopencv_video.so.2.4
libopencv_core.so              libopencv_imgproc.so        libopencv_ocl.so              libopencv_video.so.2.4.9
libopencv_core.so.2.4          libopencv_imgproc.so.2.4    libopencv_ocl.so.2.4          libopencv_videostab.so
libopencv_core.so.2.4.9        libopencv_imgproc.so.2.4.9  libopencv_ocl.so.2.4.9        libopencv_videostab.so.2.4
libopencv_features2d.so        libopencv_legacy.so         libopencv_photo.so            libopencv_videostab.so.2.4.9
libopencv_features2d.so.2.4    libopencv_legacy.so.2.4     libopencv_photo.so.2.4        pkgconfig
libopencv_features2d.so.2.4.9  libopencv_legacy.so.2.4.9   libopencv_photo.so.2.4.9      python2.7
libopencv_flann.so             libopencv_ml.so             libopencv_stitching.so
libopencv_flann.so.2.4         libopencv_ml.so.2.4         libopencv_stitching.so.2.4
libopencv_flann.so.2.4.9       libopencv_ml.so.2.4.9       libopencv_stitching.so.2.4.9

```
   使用下面的动态库管理命令ldconfig，让opencv的相关链接库被系统共享
```
    sudo ldconfig -v  
```

如果成功的话，我的检测方法如下，正确的结果将会发现前面动态库的名字
```
sudo ldconfig -v >temp.so.txt && cat temp.so.txt|grep opencv

```


##2.5 指定头文件位置
   完成了动态库的共享，还不能使用opencv来编程，还需要为程序指定openvc的头文件位置。这里使用pkg-config命令来完成。首先在 /etc/profile 中添加

```
export  PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig  
```
   pkg-config 维护着一个关于opencv的配置文件，这个文件（opencv.pc）在目录 /usr/local/lib/pkgconfig，这个文件记录着opencv的一些动态库信息，还有头文件信息

输入pkg-config --cflags opencv 和pkg-config --libs opencv ,可以发现以下信息。

正确的结果是如下：
```
root@noya-VirtualBox:/usr/local/lib# pkg-config --cflags opencv
-I/usr/local/include/opencv -I/usr/local/include 


root@noya-VirtualBox:/usr/local/lib# pkg-config --libs opencv


/usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_ocl.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so -lrt -lpthread -lm -ldl 
```

#3 测试
## 编译sample
   在解压的opencv目录下找到 samples/c/build_all.sh，运行该文件
```
noya@noya-VirtualBox:/media/sda_m/opencv-2.4.9/samples/c$ ./build_all.sh 
compiling contours.c
compiling convert_cascade.c
compiling delaunay.c
compiling fback_c.c
compiling morphology.c
compiling motempl.c
compiling polar_transforms.c
compiling pyramid_segmentation.c
compiling adaptiveskindetector.cpp
compiling bgfg_codebook.cpp
compiling blobtrack_sample.cpp
compiling facedetect.cpp
compiling find_obj.cpp
compiling find_obj_calonder.cpp
compiling find_obj_ferns.cpp
compiling latentsvmdetect.cpp
compiling mser_sample.cpp
compiling mushroom.cpp
compiling one_way_sample.cpp
compiling smiledetect.cpp
compiling tree_engine.cpp

```
## list all the executive

```
find . -perm /u=x,g=x,o=x
```
结果是
```
.
./find_obj_calonder  #?
./adaptiveskindetector #?
./delaunay #ok

./facedetect #ok
./mser_sample #？
./blobtrack_sample #？
./one_way_sample #?
./latentsvmdetect  #ok
./tree_engine #?
./bgfg_codebook #?
./motempl #?
./fback_c #?
./polar_transforms #?
./contours #ok
./find_obj #Ok 
./smiledetect #ok
./mushroom #?
./convert_cascade  #?
./morphology #ok
./pyramid_segmentation #ok
./find_obj_ferns   #?

```

期中末尾表示为 #?是当前不知道作用的，其他的ok都有结果的


##example find object
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/find_obj.png "")
smile detect
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_smile_detect.png "")

face detect
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_face_detect.png "")


### 动态的 delaunay 三角+ voronoi分割

基础参考：
http://blog.csdn.net/berguiliu/article/details/25003055

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_delaunay.png "")
```
This program demostrates iterative construction of
delaunay triangulation and voronoi tesselation.
It draws a random set of points in an image and then delaunay triangulates them.
```

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_mser.png "")

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_latentsvm.png "")

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_contours.png "")

![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_pyramid.png "")

###有趣 morphology
基础:
http://blog.csdn.net/poem_qianmo/article/details/24599073
![](https://code.csdn.net/titer1/pat_aha/blob/master/Markdown/0415_morphology.png "")
 



###fail example

find_obj_ferns
```
./find_obj_ferns box.png box_in_scene.png 

This program shows the use of the "fern" plannar PlanarObjectDetector point
descriptor classifier
Usage:
./find_obj_ferns <object_filename> <scene_filename>, default: box.png and box_in_scene.png

Trying to load box.png_model.xml.gz ...
The file not found and can not be read. Let's train the model.
Step 1. Finding the robust keypoints ...

```

#### adaptiveskindetector
需要一个照片序列
```
./adaptiveskindetector

This program demonstrates the contributed flesh detector CvAdaptiveSkinDetector which can be found in contrib.cpp
Usage: 
./adaptiveskindetector fileMask firstFrame lastFrame

Example: 
./adaptiveskindetector C:\VideoSequences\sample1\right_view\temp_%05d.jpg  0  1000
   iterates through temp_00000.jpg  to  temp_01000.jpg

```


#### find_obj_calonder:Calonder point descriptor classifierSURF
```
./find_obj_calonder
This program shows the use of the Calonder point descriptor classifierSURF is used to detect interest points, Calonder is used to describe/match these points
Format:
   classifier_file(to write) test_image file_with_train_images_filenames(txt)   or
   classifier_file(to read) test_image

```


###others
- blobtrack_sample 输入未知


- one_way_sample  2 photo need

- tree_engine

- /bgfg_codebook

```
Learn background and find foreground using simple average and average difference learning method:
Originally from the book: Learning OpenCV by O'Reilly press
```

##查看example下面的图片
```
 ll *.jpg
eog 查看下面的图片
```

#小结
搭建环境
玩玩example
找到兴趣方向

- 动态的 delaunay 三角+ voronoi分割

基础参考：
http://blog.csdn.net/berguiliu/article/details/25003055

- 有趣 morphology
基础:
http://blog.csdn.net/poem_qianmo/article/details/24599073



#参考

http://blog.csdn.net/surgewong/article/details/39078251



#windows install
参考 浅墨

#get sample
form git or pan

```
error 1:	error C1083: 无法打开包括文件:“opencv2/opencv.hpp”: 
```

vc++目录
- include
	- include
	- opencv2
	- opencv
- lib
- linker input
	- opencv_core248d.lib
	- opencv_imgproc248d.lib
	- opencv_highgui248d.lib

```
error 2: 丢失opencv_core*.dll
```
至此，环境变量在里面，但是竟然一直找不到。只有使用蛮力法，全部拷贝
深入c学习笔记

作者：titer1
出处：https://code.csdn.net/titer1
声明：本文采用以下协议进行授权： 自由转载-非商用-非衍生-保持署名|[Creative Commons BY-NC-ND 3.0](http://creativecommons.org/licenses/by-nc-nd/3.0/deed.zh) ，转载请注明作者及出处。
tips:https://code.csdn.net/titer1/pat_aha/blob/master/Markdown

-------

#code 1
```c
int main()
{
    int a = 42;
    printf(“%d\n”, a);
}
```

```
这段代码在C++下无法编译，因为C++需要明确声明函数
这段代码在C的编译器下会编译通过，因为在编译期，编译器会生成一个printf的函数定义，并生成.o文件，链接时，会找到标准的链接库，所以能编译通过。
 但是，你知道这段程序的退出码吗？在ANSI-C下，退出码是一些未定义的垃圾数。但在C89下，退出码是3，因为其取了printf的返回值。为什么printf函数返回3呢？因为其输出了’4′, ‘2’,’\n’ 三个字符。而在C99下，其会返回0，也就是成功地运行了这段程序。你可以使用gcc的 -std=c89或是-std=c99来编译上面的程序看结果。
另外，我们还要注意main()，在C标准下，如果一个函数不要参数，应该声明成main(void)，而main()其实相当于main(…)，也就是说其可以有任意多的参数。
```
小结：
- 不同编译器反应
- main退出码 (c89/c99),标准之说
- main parameter

#code snipet 2
```
示例一
1
int a=41; a++; printf("%d\n", a);
示例二
1
int a=41; a++ & printf("%d\n", a);
示例三
1
int a=41; a++ && printf("%d\n", a);
示例四
1
int a=41; if (a++ < 42) printf("%d\n", a);
示例五
1
int a=41; a = a++; printf("%d\n", a);
```

```
而示例二和五的行为则是未定义的。
关于这种未定义的东西是因为Sequence Points的影响（Sequence Points是一种规则，也就是程序执行的序列点，在两点之间的表达式只能对变量有一次修改），因为这会让编译器不知道在一个表达式顺列上如何存取变量的值。
比如a = a++，a + a++，不过，在C中，这样的情况很少。

```

- 小结 序列点
	在两点之间的表达式只能对变量有一次修改

#code snipet 3 数组取地址

```
#include <stdio.h>
int main(void)
{
    int a[5];
    printf("%x\n", a);
    printf("%x\n", a+1);
    printf("%x\n", &a);
    printf("%x\n", &a+1);
}
假如我们的a的地址是：0Xbfe2e100, 而且是32位机，那么这个程序会输出什么？

```

```
第一条printf语句应该没有问题，就是 bfe2e100
第二条printf语句你可能会以为是bfe2e101。那就错了，a+1，编译器会编译成 a+ 1*sizeof(int)，int在32位下是4字节，所以是加4，也就是bfe2e104
第三条printf语句可能是你最头疼的，我们怎么知道a的地址？我不知道吗？可不就是bfe2e100。那岂不成了a==&a啦？这怎么可能？自己存自己的？也许很多人会觉得指针和数组是一回事，那么你就错了。如果是 int *a，那么没有问题，因为a是指针，所以 &a 是指针的地址，a 和 &a不一样。但是这是数组啊a[]，所以&a其实是被编译成了 &a[0]。

第四条printf语句就很自然了，就是bfe2e104。还是不对，因为是&a是数组，被看成int(*)[5]，所以sizeof(a)是5，也就是5*sizeof(int)，也就是bfe2e114。
```
##小结
  第一轮分析的时候，我在这里犯错误，数组地址的运算
  - 数组a ,&a 在数值上一致
  - 但是一旦移动，后者是int(*)[5]，自然结果不一样


  
 #code snipet 4
 http://coolshell.cn/articles/873.html














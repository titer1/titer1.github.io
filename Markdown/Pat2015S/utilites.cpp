
#include <stdio.h>

	/************************************************************************/
	/*                  主函数的跳板  test_template_main                                                 */
	/************************************************************************/




	



	/************************************************************************/
	/* test_const_volatile_static_in_class main function                 
	*关键词 来开会
	*测试 const voliatile static对于 类的内部函数，单独对于一个函数nothing use
	*注意 声明和实现都要加上对应的关键字
	* const结尾的内部函数，有说法是里面只能用const,这是误解。其实本质是不能修改变量
	*http://www.cnblogs.com/zhangjing0502/archive/2012/02/28/2371221.html
	*/
	/************************************************************************/
class utilities_one
{
public :
	//static void static_fun_const() const;

	/*
	const修饰符用于表示函数不能修改成员变量的值，该函数必须是含有this指针的类成员函数，函数调用方式为thiscall
而类中的static函数本质上是全局函数，调用规约是__cdecl或__stdcall,不能用const来修饰它
	*/
};
class utilities_gadget
{//方法论：总之修饰变量ez,修饰函数的话，必然涉及到可以调用的内部成员（放在后面，eg const(no modify),vilatie）,（放在前面static ,no this pointer）
public:
	void Post_volatile() volatile;
	void Post_const() const;
	//static void static_fun_const() const; //对于属于累，而非对象的，不能用const
	//virtual static int BeginNo();   //still                //错误！

	static void static_fun();//核心，你懂，this指针，属于类，zhaoxing_fail

	void normal(){};
	char mC_1;
	int mI_1;
	static int  mSI_1;


	static  utilities_gadget mClass_utilities_gadget;
	utilities_gadget * mpClass_utilities_gadget;
	//utilities_gadget & mY_utilities_gadget; //引用fail
	 //utilities_gadget mClass_noStatic_utilities_gadget;//加static ok,解释可能导致递归

	utilities_one mClass_utilities_one;//可以compile,how to init ..ok pass

};

void utilities_gadget::static_fun(){ //非静态的函数/成员都不能调用
	//mI_1;
	mSI_1;
	//normal();
}
void utilities_gadget::Post_volatile() volatile
{
	int x=0;
}
void utilities_gadget::Post_const() const
{
	mI_1;
	//	mI_1++;//由于正在通过常量对象访问“mI_1”，因此无法对其进行修改
}

void test_const_volatile_static_in_class()
{
	class utilities_gadget m_utilities_gadget;
	const class utilities_gadget m_const_utilities_gadget;

	m_utilities_gadget.normal();
	//m_const_utilities_gadget.normal();//const类仅认同const内部函数，哪怕没有内容  nothing 能将“this”指针从“const utilities_gadget”转换为“utilities_gadget &”	c:\users\vanny\documents\visual studio 2010\projects\demo\csdn\markdown\pat2015s\utilites.cpp	46

	m_utilities_gadget.Post_const();
	m_const_utilities_gadget.Post_const();//果然const类 和 const修饰的函数是天生一对
	return;

	//http://fanyao246387.blog.163.com/blog/static/6831347120091044318600/
}



// volatile 

//#define TEST_ADD_CONST_BEHIND_FUNCTION
#ifdef TEST_ADD_CONST_BEHIND_FUNCTION
void check_fun_const() const//非成员函数上不允许修饰符
{
	//int x=0;
	const int y =0;
}
void test_const()
{
const int x=10;
//x= 11;
check_fun_const();

}
#endif



/************************************************************************/
	/*                  关键字 volatile 经典问题，涉及汇编
	*1） int a=0 b =2 ,c=3; fun(a,b,3);//是否添加vilatie为列子
					*如果不加，编译器可能fun(0,2,3），优化了，这里竟然没有涉及寄存器
	* 我知道，不从中间缓存的寄存器里取

	* 比较难得就是有序性，这发生在多线程。 
	*{ sth =1 ; flag = ture;}
	*{ if(flag == ture){  assert(sth ==1);} }
	*鉴于编译器可能乱序优化，就可能发生先置flag,而sth没有赋值为1
	*最笨的方法就是两种变量都加上volatile
	*Volatile变量与非Volatile变量的顺序，编译器不保证顺序，可能会进行乱序优化。同时，C/C++ Volatile关键词，并不能用于构建happens-before语义
	* 多线程案列，happen-before语义（保证线程1在线程2之前运行完）
	* http://hedengcheng.com/?p=725
	*/
	/************************************************************************/


	/************************************************************************/
	/*                  关键字 cast各种，投入时间 和 产出不成正比，见cnblog                                                */
	/************************************************************************/

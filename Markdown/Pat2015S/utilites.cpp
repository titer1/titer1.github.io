
#include <stdio.h>

	/************************************************************************/
	/*                  ������������  test_template_main                                                 */
	/************************************************************************/




	



	/************************************************************************/
	/* test_const_volatile_static_in_class main function                 
	*�ؼ��� ������
	*���� const voliatile static���� ����ڲ���������������һ������nothing use
	*ע�� ������ʵ�ֶ�Ҫ���϶�Ӧ�Ĺؼ���
	* const��β���ڲ���������˵��������ֻ����const,������⡣��ʵ�����ǲ����޸ı���
	*http://www.cnblogs.com/zhangjing0502/archive/2012/02/28/2371221.html
	*/
	/************************************************************************/
class utilities_one
{
public :
	//static void static_fun_const() const;

	/*
	const���η����ڱ�ʾ���������޸ĳ�Ա������ֵ���ú��������Ǻ���thisָ������Ա�������������÷�ʽΪthiscall
�����е�static������������ȫ�ֺ��������ù�Լ��__cdecl��__stdcall,������const��������
	*/
};
class utilities_gadget
{//�����ۣ���֮���α���ez,���κ����Ļ�����Ȼ�漰�����Ե��õ��ڲ���Ա�����ں��棬eg const(no modify),vilatie��,������ǰ��static ,no this pointer��
public:
	void Post_volatile() volatile;
	void Post_const() const;
	//static void static_fun_const() const; //���������ۣ����Ƕ���ģ�������const
	//virtual static int BeginNo();   //still                //����

	static void static_fun();//���ģ��㶮��thisָ�룬�����࣬zhaoxing_fail

	void normal(){};
	char mC_1;
	int mI_1;
	static int  mSI_1;


	static  utilities_gadget mClass_utilities_gadget;
	utilities_gadget * mpClass_utilities_gadget;
	//utilities_gadget & mY_utilities_gadget; //����fail
	 //utilities_gadget mClass_noStatic_utilities_gadget;//��static ok,���Ϳ��ܵ��µݹ�

	utilities_one mClass_utilities_one;//����compile,how to init ..ok pass

};

void utilities_gadget::static_fun(){ //�Ǿ�̬�ĺ���/��Ա�����ܵ���
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
	//	mI_1++;//��������ͨ������������ʡ�mI_1��������޷���������޸�
}

void test_const_volatile_static_in_class()
{
	class utilities_gadget m_utilities_gadget;
	const class utilities_gadget m_const_utilities_gadget;

	m_utilities_gadget.normal();
	//m_const_utilities_gadget.normal();//const�����ͬconst�ڲ�����������û������  nothing �ܽ���this��ָ��ӡ�const utilities_gadget��ת��Ϊ��utilities_gadget &��	c:\users\vanny\documents\visual studio 2010\projects\demo\csdn\markdown\pat2015s\utilites.cpp	46

	m_utilities_gadget.Post_const();
	m_const_utilities_gadget.Post_const();//��Ȼconst�� �� const���εĺ���������һ��
	return;

	//http://fanyao246387.blog.163.com/blog/static/6831347120091044318600/
}



// volatile 

//#define TEST_ADD_CONST_BEHIND_FUNCTION
#ifdef TEST_ADD_CONST_BEHIND_FUNCTION
void check_fun_const() const//�ǳ�Ա�����ϲ��������η�
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
	/*                  �ؼ��� volatile �������⣬�漰���
	*1�� int a=0 b =2 ,c=3; fun(a,b,3);//�Ƿ����vilatieΪ����
					*������ӣ�����������fun(0,2,3�����Ż��ˣ����ﾹȻû���漰�Ĵ���
	* ��֪���������м仺��ļĴ�����ȡ

	* �Ƚ��ѵþ��������ԣ��ⷢ���ڶ��̡߳� 
	*{ sth =1 ; flag = ture;}
	*{ if(flag == ture){  assert(sth ==1);} }
	*���ڱ��������������Ż����Ϳ��ܷ�������flag,��sthû�и�ֵΪ1
	*��ķ����������ֱ���������volatile
	*Volatile�������Volatile������˳�򣬱���������֤˳�򣬿��ܻ���������Ż���ͬʱ��C/C++ Volatile�ؼ��ʣ����������ڹ���happens-before����
	* ���̰߳��У�happen-before���壨��֤�߳�1���߳�2֮ǰ�����꣩
	* http://hedengcheng.com/?p=725
	*/
	/************************************************************************/


	/************************************************************************/
	/*                  �ؼ��� cast���֣�Ͷ��ʱ�� �� �����������ȣ���cnblog                                                */
	/************************************************************************/



#include <stdio.h>
#include <string.h>


//#define COMMIT_PAT

#define MAX_NUM 101
static int gIarr[2*MAX_NUM];

#ifdef COMMIT_PAT
int main(int argc ,char *argv[])
#else
int test_array_right_shift()
#endif

{

#define _IO
#ifdef _IO

	freopen("00_array_rightshift.txt","r",stdin);
#endif



	int mI_num_input  = 1, mI_num_shift = 0, i;

	scanf("%d %d",&mI_num_input,&mI_num_shift);
	//scanf("%d",&mI_num_input);
	//6scanf("%d",&mI_num_shift);

	for(  i =0 ; i< mI_num_input ; i++ )
		scanf("%d",&gIarr[i]);

	for ( i = mI_num_input ; i<2*mI_num_input ; i++)
		gIarr[i] = gIarr[ i - mI_num_input ] ;

	for(  i= mI_num_input - mI_num_shift ; i<2*mI_num_input - mI_num_shift ; i++ )
		if( i == 2*mI_num_input - mI_num_shift -1 )
			printf("%d\n",gIarr[i]);
		else
			printf("%d ",gIarr[i]);





	return 0;
	//cost time only 30 minutes
	/*
0	答案正确	1	232	10/10  00_array_rightshift.cpp
1	答案错误	1	360	0/3
2	答案错误	1	232	0/3
3	答案正确	1	256	2/2
4	答案正确	1	236	2/2
	*/
}

/*
一个数组A中存有N（N>0）个整数，
在不允许使用另外数组的前提下，
将每个整数循环向右移M（M>=0）个位置，
即将A中的数据由（最后M个数循环移至最前面的M个位置）。

如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。


输入样例：
6 21 2 3 4 5 6
输出样例：
5 6 1 2 3 4

1 2 3 4 5 6  1 2 3 4 5 6

*/
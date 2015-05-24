//#include "stdafx.h"
//#define COMMIT_PAT
#define debugOutput printf



#include <stdio.h>
#include <string.h>
#include <math.h>








// mCnt以内的素数

bool judgeP(int n)
{
bool ret=0;
	int i=2;

	if(n<2) return false; //not valid
	
	for( i =2; i<= sqrt(double(n)); i++ )
	{
		if( (n % i) == 0 ) //
			return false;


	}

//debugOutput(" ~%d\t",n); 
return true; 
}

//produce P

#define P_CNT 100
static int gIarr[P_CNT];
int gIindex=1;

void produceP(int n)
{
	if(n<2) return ;

	for (int i=2; i<=n ; i++)
		if( judgeP(i) )
		{	gIarr[gIindex++] = i;
	debugOutput("%d\t",i);
		}
	debugOutput("\n");
		
}


void test_unit_judgeP()
{
		for(int j=0; j<20;j++)
		judgeP(j);

}

#ifdef COMMIT_PAT
int main(int argc ,char *argv[])
#else
int test_sushudui()
#endif


{
	//input >0 interger



	int mIcnt=0;
	scanf("%d",&mIcnt);
	int mIresult=0;
	gIarr[0] =1 ;//init 
	

	produceP(mIcnt);

	for( int i =1 ; i< gIindex ; i++)
		if ( ( gIarr[i] - gIarr[i-1] )!=2 )
			{
				debugOutput("%d %d\n",gIarr[i] ,gIarr[i-1]);
				mIresult++;
			}

	printf("%d\n",mIresult);
		

	return 0;
	//vs工程去除 预编译头属性

	//
}



/*
0	答案正确	1	360	10/10
1	答案错误	1	360	0/2
2	答案错误	1	256	0/2
3	答案错误	1	360	0/2
4	答案错误	1	232	0/2
5	段错误	1	232	0/2

*/

/*

00-自测2. 素数对猜想 (20)


让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。


输入格式：每个测试输入包含1个测试用例，给出正整数N。
输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/
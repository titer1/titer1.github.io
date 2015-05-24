//#include "stdafx.h"

//#define COMMIT_PAT 


#ifndef COMMIT_PAT 
#define debug_output //printf
#else
 #define debug_output //printf
#endif 



#include <stdio.h>
#include <math.h>
#include <string.h>


int f15s_shalou(int y, char *ch)
{
	if(y<=0) return -1;
	//  (1+ x)^2 /2 -1  =Y ;; 1+5 --> 18-1 =17
	// (y +1  *2) ,sqrt , -1 ... odd

	//check input , y interger ,>0
	
	
	int mIx = sqrt( double( (y + 1) *2 ))  -1 ;
	//int mIx =  pow( double(1+y),2)/2 -1;

	if ( mIx %2 == 0)
		mIx = mIx -1;

	//only 1
	//print first
	int i=0 ,j=0,k=0;
	for ( i = mIx; i >0 ; i -=2) 
	{
		for( k =0; k< (mIx-i) /2; k++)
			printf(" ");
		for( j=i; j>0; j-- )
			printf("%c",*ch);
		for( k =0; k< (mIx-i) /2; k++) // ask it ????
			printf(" ");

		printf("\n");

	}


	//now 1 

	for( i = 3; i<=mIx; i+= 2)
	{
		for( k =0; k< (mIx-i) /2; k++)
			printf(" ");
		for( j=i; j>0; j-- )
			printf("%c",*ch);
		for( k =0; k< (mIx-i) /2; k++) // ask it ????
			printf(" ");

		printf("\n");	
	}
//leave
	// y - ( ( 1+ mIx)^2 /2 -1 )
	int mIremain = y - pow( double(1+mIx)  ,2)/2+1;
	if (mIremain)
		printf("%d\n",  mIremain );
//debug("hi\n");
return 0;
}





#ifndef COMMIT_PAT 
int Test_main_1_shalou( )
#else
int main(int argc, char argv[])
#endif

{
	int mIinput;
	char mCinput;


#if 0 
	f15s_shalou(1000,'*');//
#else

	scanf("%d %c",&mIinput,&mCinput);

	for(int i=0; i <mIinput;i++)
	{
		f15s_shalou(i,&mCinput);//
		debug_output("===%d end\n",i);
	}
#endif

	return 0;

	//提交时
	//format need the info right space.. cost time :40 minuts+20 minuts;
	//格式 ok
	//开启多文件简易调试的方法
	//put it ,ok 
	//不确定处理*后面的空格问题
	//leave to do .clean and beauty my codes 
	//已经达到目标，give up

}
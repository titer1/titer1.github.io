

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
0	����ȷ	1	232	10/10  00_array_rightshift.cpp
1	�𰸴���	1	360	0/3
2	�𰸴���	1	232	0/3
3	����ȷ	1	256	2/2
4	����ȷ	1	236	2/2
	*/
}

/*
һ������A�д���N��N>0����������
�ڲ�����ʹ�����������ǰ���£�
��ÿ������ѭ��������M��M>=0����λ�ã�
����A�е������ɣ����M����ѭ��������ǰ���M��λ�ã���

�����Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����

�����ʽ��ÿ���������һ��������������1������N ( 1<=N<=100)��M��M>=0������2������N��������֮���ÿո�ָ���

�����ʽ����һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�


����������
6 21 2 3 4 5 6
���������
5 6 1 2 3 4

1 2 3 4 5 6  1 2 3 4 5 6

*/
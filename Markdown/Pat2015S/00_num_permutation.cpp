
//#define COMMIT_PAT

#include <stdio.h>
#include <string.h>
#include <memory.h>


#include <math.h>


int gI_bitmap[10]; // one add ,anther minus it

unsigned long long atol(  char * str)
{
unsigned long long local=0;
	
	int mI_index=0, mI_len=0;
	while( str[mI_index++] ); //check valid char ,check null str, check big impossible float -
	mI_index --;
	
	mI_len=mI_index ;//-1; save it


	for(  ; mI_index >0 ;mI_index --)
	{
		//long long x = pow((double)10,(mI_len-mI_index));
		local += (str[mI_index -1 ] - '0')*pow((double)10,(mI_len-mI_index) );// 0 ��x'
		//local += x;

		gI_bitmap[str[mI_index -1 ] - '0'] ++;
	}


	//check local
	return local;

	//Ϊ��ʡlength�ĳ��ȣ�����pow�Ĵ��븽����һ��Ҫϸ��(str[mI_index -1 ] - '0')�Ĵ���

}
bool mini_ltoa_check_bitmal(unsigned long long input){

	//get digits??
	int remain=0;
	while(input)
	{
		remain = input % 10 ;
		gI_bitmap[remain] -- ;
		if(gI_bitmap[remain] <0)
			return false;
		input = input / 10 ; //find last;

		//ʣ�µ�0 ������ ok deal ,not same >>
	}
	return true;

}

#ifndef COMMIT_PAT
void test_atol()
{
	printf("%d\n",atol("2"));
	printf("%d\n",atol("12345678"));

	//printf("%d",atol("-1"));
	//printf("%d",atol("1.0"));
}

#endif



#ifdef COMMIT_PAT
int main(int argc, char * argv[])
#else
int test_num_permutation()
#endif
{

#ifndef COMMIT_PAT
	freopen("00_num_permutation.txt","r",stdin);
#endif

	char mCh_input[21],mCh_double[41];//������Ӧ����һ����
	unsigned long long mL_input=0, mL_double=0;
	scanf("%s",mCh_input);//	//one positive integer with no more than 20 digits.
	
	mL_input =atol(mCh_input);
	
	mL_double = mL_input *2;//* mL_input ;

	//check the bitmap
	
	if ( !mini_ltoa_check_bitmal(mL_double))
	{
		printf("No\n"); // exist another 
		return -1;
		printf("%llu\n",mL_double);
	}

	//check the datamap
	for(int i =0 ;i< 10; i++) // not enough
		if( gI_bitmap[i] )
		{printf("No\n");
		printf("%llu\n",mL_double);
		return -1;
		}
	
	printf("Yes\n");
	printf("%llu\n",mL_double);



	//check it;

return 0;
//����printf������˵������з��ŵ�long long���ͱ��������÷���%lld�����޷��ŵ�unsigned long long����Բ���%llu��
//���� ato*ϵ�У�
//time cost : 50 minutes
// 2^32 .... 4000 000 000 //int not enough ,big data
//           16 ...18zero...
// not sure long can hold it
//big multipy ?? ����Ҫ

//input

//test_atol();
}

/* ��һ�� �����Ǿֲ�ϸ��,todo
0	����ȷ	1	256	3/3
1	����ȷ	1	364	2/2
2	���ط���	1	236	0/2
3	����ȷ	1	364	2/2

4	���ط���	1	256	0/2
5	���ط���	1	236	0/3
6	���ط���	1	364	0/3
7	���ط���	1	364	0/3

*/
/*
Notice that the number 123456789 is a 9-digit number 
consisting exactly the numbers from 1 to 9,
with no duplication. 
Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. 
That is, double a given number with k digits,
you are to tell if the resulting number consists of
only a permutation of the digits in the original number.


Input Specification:

Each input file contains one test case. 
Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes"
if doubling the input number gives a number
that consists of only a permutation of the digits in the original number,
or "No" if not.
Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798

*/
// Pat2015S.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <stdio.h>

extern int Test_main_1_shalou( );
extern int test_sushudui();
extern int test_array_right_shift();
extern int test_num_permutation();
extern void test_template_main(int);
extern int test_graph_build_deep_broad();

int main(int argc, char * argv[])
{
	int choice=0;

	while(1)
	{
		printf("\nchoice 1 :打印沙漏\n");
		//printf("choice >66601 : show my code template demo\n");
		printf("66601:the binary test\n");
		printf("66602:the deep broad search\n");

		scanf("%d",&choice);
		

		switch( choice )
		{
		case 1:
			printf("please input shape num and shape character (eg:19 *)\n");
			Test_main_1_shalou();
			choice = 0;
			break;
		case 666:

			break;
		default :
			printf("now demo code \n");
			test_template_main(choice);
			break;
		}
	}
	//Test_main_1_shalou();

	//test_sushudui();

	//test_array_right_shift();

	test_num_permutation();

	return 0;
	//later shell mode
}

/************************************************************************/
	/*                 这仅仅是代码模板                                             */
	/************************************************************************/



	/************************************************************************/
	/*                 头部也有趣，涵盖 list vetor queue hashmap                                             */
	/************************************************************************/



#include <stdio.h>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <vector>

using namespace std;



	/************************************************************************/
	/*                  主函数的跳板  test_template_main                                                 */
	/************************************************************************/

//this this macro test_template_main get the main entrace


	/************************************************************************/
	/*                  tree                                                 */
	/************************************************************************/
//#define tune_f_awb_tray
#ifdef tune_f_awb_tray
#endif

	/************************************************************************/
	/*                 graph basic //build deep broad                                                     */
	/************************************************************************/

//隔离
#define TUNE_GRAPH
#ifdef TUNE_GRAPH

#include <vector>
#include <queue>
#include <list>//？？
#include <map>//??
#include <stdio.h>

using namespace std;
const int maxN = 1024; 
typedef struct N{
	int to;
	int cost;
	int dis;//distance
	friend bool operator <( N a,N b)
	{
		return a.dis < b.dis;
	}
}awbNode;

vector<awbNode> graf[maxN];
int flagD[maxN];
int flagB[maxN];
#define _LOG printf
int deep(int v){
	//v = v - 1; //fix zero start
	//if( v< 0) return 0;

	if( !flagD[v]) //init	
	{	flagD[v] =1;
		printf("%d\t",v);//do diy

	sort(graf[v].begin(), graf[v].end()); 
	
	for(int i=0; i< graf[v].size(); i++)
		if(! flagD[ graf[v][i].to ] )
		{
			deep( graf[v][i].to );
		}
	}
	return 1;
}

int broad(int v){
	
	// unvisited
	/*if(! flagB[v] ){
		flagB[v] = 1
	} */

	queue<int> hiQ;
	hiQ.push(v);

	int front =0;
	while (! hiQ.empty() ){
	front = hiQ.front();
	hiQ.pop();//take care

	//set flag
	if( flagB[front] == 0)
	{
		printf("%d\t",front);	
		flagB[front]=1;
	}else
		continue;
	//give hello to neighbor
	for( int i=0; i< graf[front].size(); i++)
		if (! flagB [ graf[front][i].to]){
			hiQ.push( graf[front][i].to );	
		}
	}
return 1;
}
void graf_build(int nodeN, int edgesN){
	int i ,j;
	int from,cost,to;
	awbNode tempNode;
	for(i =0; i< edgesN; i++)//build cmx or adj
	//from to ,cost;
	{
		scanf("%d%d%d",&from,&to,&cost);
		
		from =from -1;//一句话相关zero转换在deep /broad哪里，而非deep broad内部
		to = to -1; //for 0 zero start
		
		tempNode.to = to;
		tempNode.cost = cost;
		graf[from].push_back(tempNode);

#define DIRECTION
#ifdef DIRECTION
		tempNode.to = from;
		graf[to].push_back(tempNode);

#endif
	
	}


}
int test_graph_build_deep_broad()
{
//cmx is the basic, and later is 
#define _FILE
#ifdef _FILE
	freopen("test_graph_build.txt","r",stdin);
#endif	
	int nodeN=0, edgesN=0;
	//fflush
	scanf("%d%d",&nodeN, &edgesN);
	graf_build(nodeN,edgesN);
	deep(0);//0?? start
	printf("\n");

	broad(0);//pass it ,0 start
	printf("\n");
return 1;
//漂亮完成，遇到while 1中反复打印的情况
//针对 0 zero 找对入口

}
#endif


	/************************************************************************/
	/*                 string ...                                                    */
	/************************************************************************/





	/************************************************************************/
	/*                  binary search                                                     */
	/************************************************************************/

//but let it out

int  binary_search(int arr[], int low, int high , int target)
{
	//recursive

	if( low > high) return -1;//not find it

	int mid = low + (high - low)>>1;//shift eazy bug
	if(arr[mid ] < target)//right
		//low = mid +1;
		binary_search(arr,mid+1, high , target);
	else if ( arr[mid] > target )
		binary_search(arr,low,mid -1 , target);
	else
		return mid;//postion
}
int binary_search_iterative(int arr[], int low, int high ,int target){
	
	//consider equal ?
	int mid;
	while( low <= high)
	{
			mid = low +( high - low)>>1;
			if( arr[mid ] <target)
				low = mid +1;
			else if ( arr[mid] > target)
				high = mid -1;
			else
				return mid;
	}
	return -1;
}

#include <ctime>
clock_t start,finish;
 
#define TIME_COST(FUNC) start=clock();\
	FUNC;\
	finish=clock();\
	printf(" cutoff =%4d ,%s \ttime():%ld ms\n",Cutoff,#FUNC,(finish-start));//CLOCKS_PER_SEC);

void test_binary_search()
{
	//test ordered data
	int a[10] = { 1 ,2,3,4,5,6,7,8,9,10};
	int *b= a;
	int *c = a;
	int req = 5;	
	printf("find pos for %d %d\n ",binary_search(b,0,sizeof(a)/sizeof(int) - 1 ,req),req);

	printf("iterative find pos for %d %d\n ",binary_search_iterative(c,0,sizeof(a)/sizeof(int) - 1 ,req),req);

	return;
	//todo;
	//改善输入输出
	//出现shift bug ,编写时间是 20 minutes;
	//可以使用 我的 time宏来测时间 ,
}

void test_template_main(int choice){

	switch(choice)
	{
	case 66601:
		test_binary_search();
		break;
	case 66602:
		test_graph_build_deep_broad();
		break;
	default:
		printf("not find match\n");
		break;
	
	}

	

}
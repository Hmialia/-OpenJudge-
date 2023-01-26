#include <stdio.h>
#include <iostream>
using namespace std;
#define MaxSize 100				//顺序队的初始分配空间大小
typedef char ElemType;			//假设顺序队中所有元素为int类型
typedef struct
{	ElemType data[MaxSize];		//保存队中元素
	int front,rear;				//队头和队尾指针
} SqQueue;


void InitQueue(SqQueue &sq)		//初始化队列
{
	sq.rear=sq.front=0;			//指针初始化
}

void DestroyQueue(SqQueue sq)  //销毁队列
{    }

int EnQueue(SqQueue &sq,ElemType x)//进队
{	if ((sq.rear+1) % MaxSize==sq.front)	//队满上溢出
	return 0;
	sq.rear=(sq.rear+1) % MaxSize;			//队尾循环进1
	sq.data[sq.rear]=x;
	return 1;
}

int GetHead(SqQueue sq,ElemType &x){//取队头元素
	if(sq.rear==sq.front)
		return 0;
	x=sq.data[(sq.front+1)%MaxSize];
	return 1;
}

int DeQueue(SqQueue &sq,ElemType &x)		//出队
{	if (sq.rear==sq.front)					//队空下溢出
	return 0;
	sq.front=(sq.front+1) % MaxSize;		//队头循环进1
	x=sq.data[sq.front];
	return 1;
}

int QueueEmpty(SqQueue sq)//判断队空
{	if (sq.rear==sq.front) return 1;
	else return 0;
}

int CountNumber(SqQueue sq){
	return  (sq. rear-sq. front+ MaxSize) % MaxSize;
}

int main()
{
	//（1）初始化队列q;
	SqQueue lq;
	InitQueue(lq);
	//（2）判断队列q是否为空；
	if(QueueEmpty(lq)){
		cout<<"yes"<<endl;
	}
	else cout<<"no"<<endl;
	//（3）依次进队列元素。输入两行数据，第一行是进队字符数据的个数，第二行是具体入队的字符数据。
	int n;cin>>n;
	for(int i=0;i<n;i++){
		char x;cin>>x;
		EnQueue(lq,x);
	}		
	//（4）出队一个元素，并输出该元素；
	char x;
	DeQueue(lq,x);
	cout<<x<<endl;
	
	//（5）输出队列q的元素个数；
	cout<<CountNumber(lq)<<endl;
	//（6）依次进队列元素。输入两行数据，第一行是进队字符数据的个数，第二行是具体入队的字符数据。
	int m;cin>>m;
	for(int i=0;i<m;i++){
		char x;cin>>x;
		EnQueue(lq,x);
	}
	//（7）输出队列q的元素个数；
	cout<<CountNumber(lq)<<endl;
	//（8）输出出队序列；
	while(!QueueEmpty(lq)){
		char y;
		DeQueue(lq,y);
		cout<<y<<" ";
	}	
	cout<<endl;
	//（9）释放队列。
	DestroyQueue(lq);
	return 0;
}

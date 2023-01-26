#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace std;
#define MaxSize 100005			//顺序队的初始分配空间大小
typedef int ElemType;			//假设顺序队中所有元素为int类型
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

int find(int n,int m){
	int time[100001];
	memset(time,-1,sizeof(time));
	
	SqQueue sq;InitQueue(sq);
	
	EnQueue(sq,n);
	time[n]=0;
	
	while(!QueueEmpty(sq)){
		int x;
		DeQueue(sq,x);
		
		if(x==m)break;
		
		int next[3]={x-1,x+1,x*2};		
		for(int i=0;i<=3;i++){
			if(next[i]>=0&&next[i]<=100000&&time[next[i]]==-1){
				EnQueue(sq,next[i]);
				time[next[i]]=time[x]+1;
			}
		}
	}
	//	for(int i=0;i<40;i++){
	//		cout<<"time["<<i<<"]="<<time[i]<<endl;
	//	}
	int xxx=time[m];
	return xxx;
}

int main(){
	int n,m;
	cin>>n>>m;
	cout<<find(n,m);
	return 0;
}

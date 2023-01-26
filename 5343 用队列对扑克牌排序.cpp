#include <stdio.h>
#include <iostream>
using namespace std;
#define MaxSize 100				//顺序队的初始分配空间大小

struct card{
	char x;
	int y;
};

void InitCard(card &cd,string b){
	cd.x=b[0];
	cd.y=b[1]-48;
}

void DisplayCard(card &cd){
	cout<<cd.x<<cd.y;
}

typedef card ElemType;			//假设顺序队中所有元素为int类型
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

int main(){
	int n;
	cin>>n;
	card c[n];
	for(int i=0;i<n;i++){ 
		string b;cin>>b;
		InitCard(c[i],b);
	}
	
	SqQueue y[9];
	for(int i=0;i<9;i++){
		InitQueue(y[i]);
	}
	SqQueue x[4];
	for(int i=0;i<4;i++){
		InitQueue(x[i]);
	}
	
	for(int i=0;i<n;i++){
		EnQueue(y[c[i].y-1],c[i]);
	}
	
	for(int i=0;i<9;i++){
		cout<<"Queue"<<i+1<<":";
		for(int j=0;j<CountNumber(y[i]);j++){
			card temp;
			DeQueue(y[i],temp);
			DisplayCard(temp);cout<<" ";
			EnQueue(x[temp.x-65],temp);
			EnQueue(y[i],temp);
		}
		cout<<endl;
	}
	
	for(int i=0;i<4;i++){
		char xtemp=i+65;
		cout<<"Queue"<<xtemp<<":";
		for(int j=0;j<CountNumber(x[i]);j++){
			card temp;
			DeQueue(x[i],temp);
			DisplayCard(temp);cout<<" ";
			EnQueue(x[i],temp);
		}
		cout<<endl;
	}	
	
	for(int i=0;i<4;i++){
		for(int j=0;j<CountNumber(x[i]);j++){
			card temp;
			DeQueue(x[i],temp);
			DisplayCard(temp);cout<<" ";
			EnQueue(x[i],temp);
		}
	}
}

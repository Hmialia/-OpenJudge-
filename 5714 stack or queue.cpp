#include <stdio.h>
#include <iostream>
using namespace std;
#define MaxSize 100				//顺序队的初始分配空间大小
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

typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &st){
	st.top=-1;
}

void DestroyStack(SqStack st)
{ }



int Push(SqStack &st,ElemType x){
	if (st. top==MaxSize-1)
		return 0;
	else{ 
		st.top++ ;
		st.data[st.top]=x;
		return 1; 
	}
}

int Pop(SqStack &st,ElemType &x){
	if (st.top==-1)
		return 0;
	else{ 
		x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st, ElemType &x){
	if (st.top==-1)
		return 0;
	else{ 
		x=st.data[st.top];
		return 1; 
	}
}

int StackEmpty(SqStack st){ 
	if(st.top==-1) return 1;
	else return 0;
}

int main(){
	int t;cin>>t;
	for(int j=0;j<t;j++){
		SqQueue sq;
		SqStack st;
		InitQueue(sq);
		InitStack(st);
		int n,type,xi,xo,xq,xt;
		int flag=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>type;
			if(type==1){
				cin>>xi;
				EnQueue(sq,xi);
				Push(st,xi);
			}
			else if(type==2){
				cin>>xo;
				DeQueue(sq,xq);
				Pop(st,xt);
				if(xt!=xq&&flag==0){
					if(xo==xq){
						cout<<"Queue"<<endl;
					}
					else if(xo==xt){
						cout<<"Stack"<<endl;
					}
					flag=1;
				}
			}
		}
	}
	return 0;
}

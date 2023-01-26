#include <stdio.h>
#include<iostream> 
using namespace std;
#define MaxSize 100

typedef int ElemType;				//设置顺序表元素为int类型
typedef struct{
	ElemType data[MaxSize];			//存放顺序表的元素
	int length;						//顺序表的实际长度
} SqList;							//顺序表类型声明

void InitList(SqList &L)			//初始化顺序表L
{
	L.length=0;
}

void CreateList(SqList &L,ElemType a[],int n)	//整体创建顺序表L
{
	int i,k=0;						//k累计顺序表L中的元素个数
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//向L中添加一个元素
		k++;						//L中元素个数增1
	}
	L.length=k;						//设置L的长度
}

void Compare(SqList&L,ElemType h,int &n){
	n=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]<=h)n++; 
	}
	return;
}

int main()
{
	SqList L;
	int n=10;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	CreateList(L,a,n);
	int h;
	cin>>h;
	int app=0;
	Compare(L,h+30,app);
	cout<<app<<"\n";
	return 0;
}

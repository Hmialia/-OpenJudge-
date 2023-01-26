#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;			
typedef struct{	
	ElemType data[MaxSize];		
	int length;					
} SqList;	

void InitList(SqList &L)		
{
	L.length=0;
}

int DelElem(SqList &L,int i){
	if (i<1 || i>L.length)			
		return 0;
	for (int j=i;j<L.length;j++)		
		L.data[j-1]=L.data[j];
	L.length--;						
	return 1;
}

void DispList(SqList L){
	int i;
	for (i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}

int GetLength(SqList L){
	return L.length;
}

int InsElem(SqList &L,ElemType x,int i)	{	
	if (i<1 || i>L.length+1)	
		return 0;
	for (int j=L.length;j>=i;j--)	
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;				
	L.length++;					
	return 1;
}

int Locate(SqList L,ElemType x)	{	
	int i=0;
	while (i<L.length && L.data[i]!=x)
		i++; 			
	if (i>=L.length) return(0);		
	else return(i+1);			
}

void CreateList(SqList &L,ElemType a[],int n){
	int i,k=0;						
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];			
		k++;						
	}
	L.length=k;			
}

int main()
{
	SqList L;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	CreateList(L,a,n);
	DispList(L);
	DelElem(L,1);
	DispList(L);
	cout<<GetLength(L)<<endl;
	InsElem(L,100,2);
	DispList(L);
	cout<<Locate(L,100);
	return 0;
}

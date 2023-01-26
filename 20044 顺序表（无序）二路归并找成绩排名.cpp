#include <stdio.h>
#define MAXSIZE 255 

typedef int ElemType;

typedef struct 
{	ElemType stu_score[MAXSIZE];		
	int length;					
} StuSqList;			

void InitList(StuSqList &L)	
{
	L.length=0;
}
void DestroyList(StuSqList L)
{
}

void CreateList(StuSqList &L,ElemType a[],int n)
{
	int i,k=0;						
	for (i=0;i<n;i++)
	{
		L.stu_score[k]=a[i];				
		k++;						
	}
	L.length=k;						
}

#include<iostream>
using namespace std;

void Reorders(StuSqList&L){  //对L重排序（从大到小）（冒泡排序）（以便找出重复）
	int temp,flags=0;
	for(int j=0;j<L.length-1;j++){
		for(int i=0;i<L.length-j-1;i++){
			if(L.stu_score[i]<L.stu_score[i+1]){
				temp=L.stu_score[i];
				L.stu_score[i]=L.stu_score[i+1];
				L.stu_score[i+1]=temp;
				flags=1;
			}
		}
		if(!flags)return;
	}
}

bool Topk(StuSqList A,StuSqList B,int k,ElemType& e){
	
	Reorders(A);Reorders(B);
	
	for(int i=0;i<A.length;i++){
		cout<<A.stu_score[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<B.length;i++){
		cout<<B.stu_score[i]<<" ";
	}
	cout<<endl;
	
	if(k<1||k>A.length+B.length)return 0;
	
	e=A.stu_score[0];
	
	int p1=0,p2=0;
	
	while(p1<A.length&&p2<B.length&&k>0){
		
		if(A.stu_score[p1]>B.stu_score[p2]){
			e=A.stu_score[p1];
			p1++;
		}
		else{
			e=B.stu_score[p2];
			p2++;
		}
		
		k--;
	}
	
	int p3=A.length+B.length;
	StuSqList C;
	
	if(p2<B.length) {
		p3=p2;
		C=B;
	}
	else if(p1<A.length){
		p3=p1;
		C=A;
	}
	
	while(p3<C.length&&k>0){		
		e=C.stu_score[p3];
		p3++;
		k--;
	}
	return 1;
}

int main()
{
	StuSqList L1,L2;
	ElemType a[MAXSIZE];
	int n, m;
	
	scanf("%d %d",&n, &m);
	
	for (int i=0;i<n;i++)	scanf("%d",&a[i]);
	CreateList(L1,a,n);
	
	for (int i=0;i<m;i++)	scanf("%d",&a[i]);
	CreateList(L2,a,m);
	
	ElemType e;
	int k;
	scanf("%d",&k);
	
	if (Topk(L1,L2,k,e))
		printf("%d %d",k,e);
	else
		printf("k=%d err",k);
	
	DestroyList(L1);
	DestroyList(L2);
}

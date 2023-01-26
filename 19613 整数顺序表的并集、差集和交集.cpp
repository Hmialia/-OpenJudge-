#include <stdio.h>
#include<iostream> 
using namespace std;
#define MaxSize 100

typedef int ElemType;				//ÉèÖÃË³Ðò±íÔªËØÎªintÀàÐÍ
typedef struct{
	ElemType data[MaxSize];			//´æ·ÅË³Ðò±íµÄÔªËØ
	int length;						//Ë³Ðò±íµÄÊµ¼Ê³¤¶È
} SqList;							//Ë³Ðò±íÀàÐÍÉùÃ÷

void InitList(SqList &L)			//³õÊ¼»¯Ë³Ðò±íL
{
	L.length=0;
}

void CreateList(SqList &L,ElemType a[],int n)	//ÕûÌå´´½¨Ë³Ðò±íL
{
	int i,k=0;						//kÀÛ¼ÆË³Ðò±íLÖÐµÄÔªËØ¸öÊý
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//ÏòLÖÐÌí¼ÓÒ»¸öÔªËØ
		k++;						//LÖÐÔªËØ¸öÊýÔö1
	}
	L.length=k;						//ÉèÖÃLµÄ³¤¶È
}

void DispList(SqList L){				//Êä³öË³Ðò±í
	int i;
	for (i=0;i<L.length;i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
}

void Deletex(SqList &L,ElemType x) //É¾³ýLÖÐËùÓÐÖµÎªxµÄÔªËØ
{	int i,k=0;
	for (i=0;i<L.length;i++)
		if (L.data[i]!=x)		//½«²»ÎªxµÄÔªËØ²åÈëµ½LÖÐ
	{	L.data[k]=L.data[i];
		k++;
	}
	L.length=k;					//ÖØÖÃLµÄ³¤¶È
}

void DelSame(SqList&L){     //É¾³ýÓÐÐò±íÄÚÁ¬Ðø³öÏÖµÄÖØ¸´ÔªËØ
	int k=0;
	for(int i=0;i<L.length-1;i++){
		if (L.data[i]!=L.data[i+1]){
			L.data[k]=L.data[i];
			k++;
		}	
	}
	L.data[k]=L.data[L.length-1];
	k++;
	L.length=k;	
}

void Reorder(SqList&L){  //¶ÔLÖØÅÅÐò£¨Ã°ÅÝÅÅÐò£©£¨ÒÔ±ãÕÒ³öÖØ¸´£©
	int temp,flags=0;
	for(int j=0;j<L.length-1;j++){
		for(int i=0;i<L.length-j-1;i++){
			if(L.data[i]>L.data[i+1]){
				temp=L.data[i];
				L.data[i]=L.data[i+1];
				L.data[i+1]=temp;
				flags=1;
			}
		}
		if(!flags)return;
	}
}

void Reorders(SqList&L){  //¶ÔLÖØÅÅÐò£¨´Ó´óµ½Ð¡£©£¨Ã°ÅÝÅÅÐò£©£¨ÒÔ±ãÕÒ³öÖØ¸´£©
	int temp,flags=0;
	for(int j=0;j<L.length-1;j++){
		for(int i=0;i<L.length-j-1;i++){
			if(L.data[i]<L.data[i+1]){
				temp=L.data[i];
				L.data[i]=L.data[i+1];
				L.data[i+1]=temp;
				flags=1;
			}
		}
		if(!flags)return;
	}
}

int RepeatTest(SqList L){        //¼ì²éÖØ¸´
	Reorder(L);
	for(int i=0;i<L.length-1;i++){
		if(L.data[i]==L.data[i+1]){
			return 1;     //ÈôÓÐÖØ¸´Ôò·µ»Ø1
		}
	}
	return 0;
}

void Intersection(SqList&A,SqList&B,SqList&C){  //Çó½»¼¯
	int k=0;
	for(int i=0;i<A.length;i++){
		for(int j=0;j<B.length;j++){
			if(A.data[i]==B.data[j]){
				C.data[k]=A.data[i];
				k++;
				break;
			}
		}
	}
	C.length=k;
	return;
}

void Subtraction(SqList&A,SqList&B,SqList&C){    //²î¼¯
	SqList CI;
	C=A;
	Intersection(A,B,CI);
	for(int i=0;i<CI.length;i++){
		Deletex(C,CI.data[i]);
	}
	return;
}

void Union(SqList&A,SqList&B,SqList&C){   //²¢¼¯
	C.length=A.length+B.length;
	for(int i=0;i<A.length;i++){
		C.data[i]=A.data[i];
	}
	for(int i=A.length;i<C.length;i++){
		C.data[i]=B.data[i-A.length];
	}
	if(A.data[0]<A.data[A.length-1])  //ÅÐ¶ÏÔ­ÐòÁÐÊÇ´Ó´óµ½Ð£»¹ÊÇ´ÓÐ¡µ½´ó£¬²¢ÒÀ´ËÆ¥ÅäÏàÓ¦µÄË³Ðò
		Reorder(C);
	else 
		Reorders(C);
	DelSame(C);
	return;
}

void UnionS(SqList&A,SqList&B,SqList&C){   //²¢¼¯S
	SqList T;
	Subtraction(B,A,T);
	C.length=A.length+T.length;
	for(int i=0;i<A.length;i++){
		C.data[i]=A.data[i];
	}
	for(int i=A.length;i<C.length;i++){
		C.data[i]=T.data[i-A.length];
	}
	return;
}

int main()
{
	SqList A,B,CU,CD,CI;
	int n1;cin>>n1;
	int a[n1];
	for(int i=0;i<n1;i++){
		cin>>a[i];
	}
	
	int n2;cin>>n2;
	int b[n2];
	for(int i=0;i<n2;i++){
		cin>>b[i];
	}
	
	CreateList(A,a,n1);
	CreateList(B,b,n2);
	
	if(RepeatTest(A)||RepeatTest(B)){
		cout<<"Repeat Error!"<<endl;
		return 0;
	}
	
	UnionS(A,B,CU);
	Subtraction(A,B,CD);
	Intersection(A,B,CI);
	
	cout<<"CU:";DispList(CU);
	cout<<"CD:";DispList(CD);
	cout<<"CI:";DispList(CI);
	return 0;
}

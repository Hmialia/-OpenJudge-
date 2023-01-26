#include<iostream>
#include<math.h>

using namespace std;
#define MaxSize 100
typedef int ElemType;

typedef int KeyType;
typedef struct{ 
	KeyType key; //存放关键字，KeyType为关键字类型
	ElemType data; //其他数据，ElemType为其他数据的类型
	
} SqType ; 

int SqSearch(SqType* R, int n, KeyType k){ //顺序查找算法
	int i=0;
	while (i<n && R[i].key!=k)
		i++;
	if (i>=n)
		return 0;
	else
		return i+1;
}

int BinSearch(SqType* R, int n, KeyType k){ //折半查找算法(要求元素有序)
	int low=0, high=n-1, mid;
	while (low<=high){ 
		mid=(low+high)/2;
		if(R[mid].key==k)
			return mid+1;
		else if (R[mid].key>k)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}

void GuluGulu(SqType* R,int n){  //对R冒泡排序
	SqType temp;
	bool flags=0;
	
	for(int j=0;j<n-1;j++){
		for(int i=0;i<n-j-1;i++){
			if(R[i].key>R[i+1].key){
				temp=R[i];
				R[i]=R[i+1];
				R[i+1]=temp;
				flags=1;
			}
		}
		if(!flags)return;
	}
}

KeyType Zhongelem(SqType* R,int n){
	double L=n;//cout<<"L="<<L<<" ";
	int Zhong=ceil(L/2)-1;//cout<<"Zhong="<<Zhong<<" ";cout<<"ceil(L/2)="<<ceil(L/2)<<" ";
	return R[Zhong].key;
}

int main(){
	int n;cin>>n;n=n*2;
	SqType R[n];
	for(int i=0;i<n;i++){
		ElemType tem;
		cin>>tem;
		R[i].key=tem;
	}
	GuluGulu(R,n);
	
	cout<<Zhongelem(R,n);
	
	return 0;
}

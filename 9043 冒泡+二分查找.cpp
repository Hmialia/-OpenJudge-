#include<iostream>
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



int BinSearch(SqType* R, int n, KeyType k,int acrea){ //折半查找算法(要求元素有序)
	if(acrea==1){
		int Binadd=0;
		int low=0, high=n-1, mid;
		while (low<=high){ 
			Binadd++;
			mid=(low+high)/2;
			if(R[mid].key==k)
				return Binadd;
			else if (R[mid].key<k)
				low=mid+1;
			else
				high=mid-1;
		}
		return -1;
	}
	else if(acrea==2){
		int Binadd=0;
		int low=0, high=n-1, mid;
		while (low<=high){ 
			Binadd++;
			mid=(low+high)/2;
			if(R[mid].key==k)
				return Binadd;
			else if (R[mid].key>k)
				low=mid+1;
			else
				high=mid-1;
		}
		return -1;
	}
}

void GuluGulu(SqType* R,int n,int acrea){  //对R冒泡排序
	if(acrea==1){
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
	else if(acrea==2){
		SqType temp;
		bool flags=0;
		
		for(int j=0;j<n-1;j++){
			for(int i=0;i<n-j-1;i++){
				if(R[i].key<R[i+1].key){
					temp=R[i];
					R[i]=R[i+1];
					R[i+1]=temp;
					flags=1;
				}
			}
			if(!flags)return;
		}	
	}
}

int main(){
	int v[10]={9,8,7,6,0,-1,10,-5,-32,66};
	SqType R[10];
	
	for(int i=0;i<10;i++){
		R[i].key=v[i];
	}
	
	int acrea;cin>>acrea;
	
	GuluGulu(R,10,acrea);
	
	int k;
	while(cin>>k){
		cout<<BinSearch(R,10,k,acrea)<<endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
#define MaxSize 100
typedef int KeyType;
typedef int ElemType;

typedef struct{ 
	KeyType key;
	ElemType data;
}SqType;

void InsertSort(SqType R[] , int n){    //直接插入排序
	int i,j;
	SqType tmp;
	
	for (i=1; i<n; i++){ 
		if (R[i-1].key<R[i].key){
			tmp=R[i];
			j=i-1;
			do{
				R[j+1]=R[j];
				j--;
			}while (j >=0 && R [j].key<tmp. key);
			R[j+1]=tmp;
		}
		
		for(int k=0;k<n;k++){
			cout<<R[k].key<<" ";
		}
		cout<<endl;
	}
}

void BinlnsertSort(SqType R[ ] , int n){  //折半插入排序
	int i,j,low,high,mid; 
	SqType tmp;
	
	for (i=1;i<n;i++){
		if (R[i-1].key>R[i].key){ 
			tmp=R[i];
			low=0; high=i-1;
			while (low<=high){ 
				mid=(low+high)/2;
				if (tmp.key<R[mid].key)
					high=mid-1; //插入点在左半区
				else
					low=mid+1; //插入点在右半区
			}
			
			for (j=i-1;j>=high+1;j--)
				R[j+1]=R[j]; 
			R[high+1]=tmp;
		}
		
		for(int k=0;k<n;k++){
			cout<<R[k].key<<" ";
		}
		cout<<endl;
	}
}



void QuickSort(SqType R[ ] , int s, int t){ //对 R[s. . t]的元素进行递增快速排序
	int i=s,j=t;
	SqType tmp;
	if (s<t){       //区间内至少存在两个元素的情况
		tmp=R[s];      //用区间的第1个元素作为基准
		while (i!=j){     //从区间两端交替向中间扫描，直至i=j为止
			while (j>i&& R[j].key>=tmp.key)
				j--; //从右向左扫描，找第1个关键字小于tmp. key的R[j]
			R[i] =R[j]; //将RCfl前移到R[i]的位置
			while (i<j && R[i].key<=tmp.key)
				i++; //从左向右扫描，找第1个关键字大于tmp. key的元素R[i]
			R[j]=R[i]; //将R[i]后移到R&]的位置
		}
		R[i] = tmp; 
		QuickSort(R, s, i-1); //对左子序列递归排序
		QuickSort(R, i+1, t); //对右子序列递归排序
	}
}


int main(){
	SqType R[MaxSize];
	int n=0;
	KeyType A[MaxSize];
	for(;n<20;n++){
		cin>>A[n];
		char x=getchar();
		if(x=='\n'){
			break;
		}
	}
	n++;
	
	for (int i=0 ; i < n; i++ )
		R[i].key=A[i];
	
	QuickSort(R, 0, n-1);
	
	if(n%2==0){
		double a=R[n/2-1].key;
		double b=R[n/2].key;
		cout<<(a+b)/2<<endl;
	}
	else {
		cout<<R[n/2].key<<endl;
	}
}


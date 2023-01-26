#include<iostream>
using namespace std;
#define MaxSize 100
typedef int KeyType;
typedef int ElemType;

typedef struct{ 
	KeyType key;
	ElemType data;
}SqType;

void InsertSort(SqType R[] , int n){    //Ö±½Ó²åÈëÅÅÐò
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

//void BinlnsertSort(SqType R[ ] , int n){  //ÕÛ°ë²åÈëÅÅÐò
//	int i,j, low, high, mid ; 
//	SqType tmp;
//	
//	for (i= 1; i < n;i++){
//		if (R[i-1] . key>R[i] . key){ 
//			tmp=R[i];
//			low=0 ; high=i-1;
//			while (low<=high){ 
//				mid= (low+high)/2;
//				if (tmp. key < R[mid] . key)
//					high=mid-1; //²åÈëµãÔÚ×ó°ëÇø
//				else
//					low=mid+1; //²åÈëµãÔÚÓÒ°ëÇø
//			}
//			
//			for (j = i-1;j >=high+1;j-- )
//				RD+i]=Rm£» R[high+l]=tmp£» ¡¨²åÈëÔ­À´µÄ R[i]
//)
//)
//)

int main(){
	SqType R[MaxSize];
	int i, n= 10;
	KeyType A[n];// = {75,87,68,92,88,61,77,96,80,72};
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for (i=0 ; i < n; i++ )
		R[i].key=A[i];
	
	InsertSort(R, n);
}


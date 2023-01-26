#include<iostream>
using namespace std;
#define MaxSize 100050;
typedef int KeyType;
typedef int ElemType;

typedef struct{ 
	KeyType key;
	ElemType data;
}SqType;

void Sift(SqType R[ ] , int low, int high){
	int i=low,j= 2*i;
	SqType tmp=R[i];
	while (j<=high){ 
		if (j<high && R[j].key>R[j+1].key)
			j++;
		if (tmp. key > R[j].key){ 
			R[i]=R[j];
			i=j;
			j = 2*i;
		}
		else break;
	}
	R[i] =tmp;
}

void HeapSort(SqType R[],int n){
	int i; 
	SqType tmp;
	for (i=n/2;i>=1;i--)
		Sift(R,i,n);
	for (i=n;i>=2;i--){ 
		tmp=R[1];
		R[1]=R[i]; R[i]=tmp; 
		Sift(R,1,i-1);
	}
}

int main(){
	int n;cin>>n;
	SqType R[n+1];
	int k=0;
	for(int i=0;i<n;i++){
		int type;cin>>type;
		if(type==1){
			int u;cin>>u;
			k++;
			R[k].key=u;
			HeapSort(R,k);		
		}
		else if(type==2){
			cout<<R[k].key<<endl;
			k--;
		}
	}
	return 0;
}

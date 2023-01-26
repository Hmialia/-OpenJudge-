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

void BinlnsertSort(SqType R[ ] , int n){  //ÕÛ°ë²åÈëÅÅÐò
	int i,j,low,high,mid; 
	SqType tmp;
	
	for (i=1;i<n;i++){
		if (R[i-1].key>R[i].key){ 
			tmp=R[i];
			low=0; high=i-1;
			while (low<=high){ 
				mid=(low+high)/2;
				if (tmp.key<R[mid].key)
					high=mid-1; //²åÈëµãÔÚ×ó°ëÇø
				else
					low=mid+1; //²åÈëµãÔÚÓÒ°ëÇø
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



void QuickSort(SqType R[ ] , int s, int t){ //¶Ô R[s. . t]µÄÔªËØ½øÐÐµÝÔö¿ìËÙÅÅÐò
	int i=s,j=t;
	SqType tmp;
	if (s<t){       //Çø¼äÄÚÖÁÉÙ´æÔÚÁ½¸öÔªËØµÄÇé¿ö
		tmp=R[s];      //ÓÃÇø¼äµÄµÚ1¸öÔªËØ×÷Îª»ù×¼
		while (i!=j){     //´ÓÇø¼äÁ½¶Ë½»ÌæÏòÖÐ¼äÉ¨Ãè£¬Ö±ÖÁi=jÎªÖ¹
			while (j>i&& R[j].key>=tmp.key)
				j--; //´ÓÓÒÏò×óÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×ÖÐ¡ÓÚtmp. keyµÄR[j]
			R[i] =R[j]; //½«RCflÇ°ÒÆµ½R[i]µÄÎ»ÖÃ
			while (i<j && R[i].key<=tmp.key)
				i++; //´Ó×óÏòÓÒÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×Ö´óÓÚtmp. keyµÄÔªËØR[i]
			R[j]=R[i]; //½«R[i]ºóÒÆµ½R&]µÄÎ»ÖÃ
		}
		R[i] = tmp; 
		QuickSort(R, s, i-1); //¶Ô×ó×ÓÐòÁÐµÝ¹éÅÅÐò
		QuickSort(R, i+1, t); //¶ÔÓÒ×ÓÐòÁÐµÝ¹éÅÅÐò
	}
}

void BubbleSort(SqType R[] , int n){
	int i,a,b,exchange;
	SqType tmp;
	a=0;b=n-1;
	while(a<b){
		exchange=0;
		
		for (i=b;i>a;i--)
			if (R[i].key>R[i-1].key){ 
			tmp=R[i];
			R[i]=R[i-1];
			R[i-1]=tmp;
			exchange=1;
		}
		a++;
		if (exchange==0)
			return;
		
		for (;i<b;i++)
			if (R[i].key<R[i+1].key){ 
			tmp=R[i];
			R[i]=R[i+1];
			R[i+1]=tmp;
			exchange=1;
		}
		b--;
		if (exchange==0)
			return;
	}
}



int main(){
	SqType R[MaxSize];
	int i, n;
	cin>>n;
	KeyType A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for (i=0 ; i < n; i++ )
		R[i].key=A[i];
	
	BubbleSort(R, n);
	
	for (i=0 ; i < n; i++ )
		cout<<R[i].key<<" ";	
	cout<<endl;
	return 0;
}

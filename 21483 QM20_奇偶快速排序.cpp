#include <iostream>
using namespace std;

#define MAX_SIZE 10002
typedef int KeyType;
typedef int ElemType;
typedef struct {	
	KeyType key;
	ElemType data;
} SqType;

void DispList(SqType ar[],int n)
{
	for (int i=0; i<n; i++) 
		cout << ar[i].key <<" ";
	cout<<endl;
}

void QuickSort(SqType R[], int s, int t, int desc)
{
	int i = t, j = s;
	SqType tmp;
	if (s < t) {
		
		if(!desc){
			tmp=R[s];      //用区间的第1个元素作为基准
			while (i!=j){     //从区间两端交替向中间扫描，直至i=j为止
				while (j<i&& R[i].key>=tmp.key)
					i-- ; //从右向左扫描，找第1个关键字小于tmp. key的R[j]
				R[j] =R[i]; //将RCfl前移到R[i]的位置
				while (i>j && R[j].key<=tmp.key)
					j++; //从左向右扫描，找第1个关键字大于tmp. key的元素R[i]
				R[i]=R[j]; //将R[i]后移到R&]的位置
			}
			R[j] = tmp; 	//TODO
		}
		else{
			tmp=R[s];      //用区间的第1个元素作为基准
			while (i!=j){     //从区间两端交替向中间扫描，直至i=j为止
				while (j<i&& R[i].key<=tmp.key)
					i-- ; //从右向左扫描，找第1个关键字小于tmp. key的R[j]
				R[j] =R[i]; //将RCfl前移到R[i]的位置
				while (i>j && R[j].key>=tmp.key)
					j++; //从左向右扫描，找第1个关键字大于tmp. key的元素R[i]
				R[i]=R[j]; //将R[i]后移到R&]的位置
			}
			R[j] = tmp; 	//TODO		
		}	
		
		
		QuickSort(R, s, i - 1, desc);
		QuickSort(R, i + 1, t, desc);
	}
}

void MySort(SqType* ar, int n){
	SqType ji[MAX_SIZE];int jn=0;
	SqType ou[MAX_SIZE];int on=0;
	
	for(int i=0;i<n;i++){
		if(ar[i].key%2==0){
			ou[on].key=ar[i].key;
			on++;
		}
		else{
			ji[jn].key=ar[i].key;
			jn++;
		}		
	}
	
	QuickSort(ji,0,jn-1,0);
	QuickSort(ou,0,on-1,1);
	int jmax=jn;int omax=on;
	int jp=0;int op=0;
	for(int i=0;i<n;i++){
		if(jp<jmax){
			ar[i]=ji[jp];
			jp++;
		}
		else{
			ar[i]=ou[op];
			op++;
		}
	}
}


int main()
{
	SqType ar[MAX_SIZE];
	int n,m;
	cin >> n;
	for (int i=0; i<n; i++) 
	{
		cin >> m;	
		ar[i].key = ar[i].data = m;
	}
	MySort(ar,n);
	DispList(ar,n);
	return 0;
}

#include<iostream>
//#include<>
using namespace std;
#define MaxSize 10002
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
	int i=s,j=t;static int n=t-s+1;
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
		
		for(int k=0;k<n;k++){
			cout//<<"("<<k<<")"
			<<R[k].key<<" ";
		}
		cout<<endl;
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

void Merge(SqType R[ ] , int low, int mid, int high){//归并排序
	//将R[low., mid]和R [mid4-1.. high]两个相邻的有序表归并为一个有序表R[low., high]
	
	SqType * R1;
	int i=low, j =mid+1, k=0 ; //k是R1的下标，i、j分别为第1、2子表的下标
	R1 = (SqType * )malloc((high-low+1) * sizeof(SqType)); //动态分配空间
	while (i <= mid && j <=high)
		if (R[i] . key <=R[j] . key){ 
		R1[k] =R[i];
		i++ ;k++ ;
	}
	else{ 
		R1[k]=R[j];
		j++;k++;
	}
	
	while (i<=mid){ 
		R1[k]=R[i];
		i++ ; k++ ;
	}
	
	while (j<=high){ 
		R1[k]=R[j];
		j++;k++ ;
	}
	for (k=0, i= low; i <=high; k++, i++)
		R[i]=R1[k];
	free(R1);
}

void MergePass(SqType R[],int length,int n){
	int i;
	for(i=0;i+2*length-1<n;i=i+2*length)
		Merge(R, i, i+length-1, i+2 * length-1);
	if (i+length-1< n)
		Merge(R, i, i+length-1, n-1);
}

void MergeSort(SqType R[ ] , int n){
	int length;
	for (length= 1;length< n;length=2 * length)
		MergePass(R, length, n);
}

void DelSame(SqType R[ ] , int n,int& k){     //删除有序表内连续出现的重复元素
	k=0;
	for(int i=0;i<n-1;i++){
		if (R[i].key!=R[i+1].key){
			R[k]=R[i];
			k++;
		}	
	}
	R[k]=R[n-1];
	k++;
}

int main(){
	
	int t;
	
	cin>>t;
	int n[t];
	int k[t];
	for(int i=0;i<t;i++){
		
		cin>>n[i];
		SqType R[n[i]];
		
		for(int j=0;j<n[i];j++){
			cin>>R[j].key;
		}
		
		MergeSort(R,n[i]);
		DelSame(R,n[i],k[i]);
		
		cout<<k[i]<<endl;
		for(int j=0;j<k[i];j++){
			cout<<R[j].key<<" ";
		}		
		cout<<endl;
		
	}
	
	return 0;
}

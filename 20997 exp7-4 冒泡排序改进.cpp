#include<iostream>
using namespace std;
void b(int a[],int l);
int main(){
	int a[]={55,2,6,4,32,12,9,73,26,37};
	int l=sizeof(a)/4;
	b(a,l);
	return 0;
}

void b(int a[],int l){
	for(int p=1;p<l;p++){
		int f=1;
		for(int i=0;i<l-p;i++)
			if(a[i]>a[i+1]){
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;	
			f=0;
		}
		if(f)break;
		for(int i=0;i<l;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}

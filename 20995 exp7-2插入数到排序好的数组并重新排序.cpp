#include<iostream>
using namespace std;
void y(int n,int a[],int x){
	int i;
	for(int l=0;l<n;l++)cout<<a[l]<<" ";
	cout<<endl;
	for(i=0;i<n;i++)if(a[i]>x)break;
	for(int j=0;j<i;j++)cout<<a[j]<<" ";
	if(i<n-1){
		cout<<x<<" ";
		for(int k=i;k<n-1;k++)cout<<a[k]<<" ";
		cout<<endl<<a[n-1];
	}
	else if(i=n-1){
		cout<<x<<" ";
		cout<<endl<<a[i];
	}
	else cout<<endl<<x;
}

int main(){
	int n=8,x;
	int a[n]={12,29,34,56,72,83,88,91};
	cin>>x;
	y(n,a,x);
	return 0;
}

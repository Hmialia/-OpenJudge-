#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int* a=new int[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=n-1;j>=0;j--){
		cout<<a[j]<<" ";
	}
	delete []a;
	return 0;
}

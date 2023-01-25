#include<iostream>
using namespace std;
int main(){
	int a[6];
	cin>>a[0];
	for(int j=1;j<6;j++){cin>>a[j];
		if(a[j-1]>a[j])a[j]=a[j-1];}
	cout<<a[5];
}

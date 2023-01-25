#include<iostream>
using namespace std;

void r(int *s,int *e){
	for(int g;e-s>0;e--,s++){
		g=*s;
		*s=*e;
		*e=g;
	}
}

void s(int *a,int n){
	for(int i=0;i<n;i++)cout<<*(a++)<<" ";
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<"original: ";
	s(a,n);
	cout<<endl;
	r(a,&a[n-1]);
	cout<<"reversed: ";
	s(a,n);
	return 0;
}

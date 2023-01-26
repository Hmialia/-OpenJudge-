#include<iostream>
using namespace std;

int cha(int n){
	return (n+n*n)/2;
}

int xv(int n){
	if (n==1) return 1;
	else return cha(n)+xv(n-1);
}

int main(){
	int n;
	cin>>n;
	cout<<xv(n)<<endl;
	return 0;
}

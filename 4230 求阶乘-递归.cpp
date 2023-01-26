#include<iostream>
using namespace std;

int jie(int n){
	if(n==0||n==1) return 1;
	else return n*jie(n-1);
}

int main(){
	int n;
	cin>>n;
	cout<<jie(n)<<endl;
	return 0;
}

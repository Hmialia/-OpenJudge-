#include<iostream>
using namespace std;

int add(int n){
	if(n<10){
		return(n);
	}
	else if(n%10==0){
		return add(n/10);
	}
	else {
		return n%10+add(n-n%10);
	}
}

int main(){
	int n;
	cin>>n;
	cout<<add(n);
	return 0;
}

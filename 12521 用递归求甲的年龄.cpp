#include<iostream>
using namespace std;

int cha(int n){
	if (n==8) return 4;
	return 2*cha(n+1)-3;
}

int main(){
	int n=1;
	cout<<cha(n)<<endl;
	return 0;
}

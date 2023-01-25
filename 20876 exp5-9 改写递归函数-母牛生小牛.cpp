#include<iostream>
using namespace std;
int mc(int n){
	if (n>0&&n<4) return 1;
	else return mc(n-1)+mc(n-3);}
int main(){
	int n;
	cin>>n;
	cout<<mc(n);
	return 0;
}

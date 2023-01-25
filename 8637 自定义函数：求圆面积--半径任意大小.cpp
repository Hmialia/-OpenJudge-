#include<iostream>
#include<iomanip>
#define p 3.14
using namespace std;
long double s(long double r){
	return p*r*r;
}
int main(){
	long double r;
	cin>>r;
	cout<<s(r)<<endl;
	return 0;
}

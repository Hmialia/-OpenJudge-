#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	int t=a;
	a=b;
	b=t;
	cout<<a<<" "<<b;
	return 0;
}

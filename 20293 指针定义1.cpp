#include<iostream>
using namespace std;
int main(){
	int a=5;
	int* p=&a;
	cout<<a<<endl<<*p<<endl;
	int b=8;
	p=&b;
	cout<<b<<endl<<*p<<endl;
	b=20;
	cout<<b<<endl<<*p<<endl;
	return 0;
}

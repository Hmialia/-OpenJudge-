#include<iostream>
using namespace std;
int main(){
	int a[]={9,8,7,6,5,4,3,2,1};
	int* p=a;
	cout<<a[4]<<endl<<*(p+7)<<endl<<p[3]<<endl<<*(p+1)<<endl<<p[1];
	p+=2;
	cout<<endl<<*p;
	return 0;
}

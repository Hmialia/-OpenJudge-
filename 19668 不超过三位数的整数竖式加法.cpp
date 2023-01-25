#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	cout<<setw(6)<<a<<endl<<"+"<<setw(5)<<b<<endl<<setfill('-')<<setw(9)<<"\n"<<setfill(' ')<<setw(6)<<c<<endl;
	return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	const double Pi=3.14159;
	double r1,r2;
	cin>>r1>>r2;
	cout
	<<setfill('*')<<setw(10)<<fixed<<setprecision(2)
	//<<Pi<<endl<<r1<<endl<<r2<<endl<<(r1+r2)<<endl<<(r2-r1)<<endl
	<<Pi*(r1+r2)*(r2-r1)<<endl;
	return 0;
}

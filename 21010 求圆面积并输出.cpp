#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	const double Pi=3.1415926;
	double s1,s2;
	double r1,r2;
	cin>>r1>>r2;
	s1=Pi*r1*r1;
	s2=Pi*r2*r2;
	cout<<setw(10)<<Pi<<setw(10)<<r1<<setw(15)<<fixed<<setprecision(2)<<s1<<endl;
	cout<<setw(10)<<Pi<<setw(10)<<r2<<setw(15)<<fixed<<setprecision(1)<<s2<<endl;
	return 0;
} 

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double x,y,z;
	cin>>x>>y>>z;
	cout<<fixed<<setprecision(2)<<((z>((x>y)?(x):(y)))?(z):((x>y)?(x):(y)))<<endl;
	return 0;
} 

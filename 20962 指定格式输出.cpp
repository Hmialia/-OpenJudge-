#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	const double e=2.718281828;
	float e0=e;
	cout<<setprecision(2)<<e0<<endl
	<<fixed<<setprecision(2)<<e<<endl;
	return 0;
} 

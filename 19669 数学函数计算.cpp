#include<iostream>
#include<iomanip>
#include<cmath>
#include<math.h>
#define Pi 3.14
using namespace std;
int main(){
	double x,y,f1,f2;
	cin>>x>>y;
	f1=1/sqrt(2*Pi)/sqrt(pow(2.71828182846,x*x));
	f2=sin(x*x+y*y)*cos(x+y)/3;
	cout<<fixed<<setprecision(8)<<f1<<endl;
	cout<<fixed<<setprecision(8)<<f2<<endl;
	return 0;
}

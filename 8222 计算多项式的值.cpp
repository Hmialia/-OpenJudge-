#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double y,x,a,b,c,d;
	cin>>x>>a>>b>>c>>d;
	y=a*x*x*x+b*x*x+c*x+d;
	cout<<fixed<<setprecision(7)<<y<<endl;
	return 0; 
}

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double h,p,s;
	cin>>h>>p;
	if(h<1) s=0;
	else if(h>=1&&h<1.4) s=p/2;
	else s=p;
	cout<<fixed<<setprecision(2)<<s<<endl;
	return 0;
}

#include<iostream>
using namespace std;
double mymin(double a,double b,double c){
	double dm;
	if(a<b)dm=a;
	else dm=b;
	if(dm<c) ;
	else dm=c;
	return dm;
}
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	cout<<mymin(a,b,c)<<endl;
	return 0;
}

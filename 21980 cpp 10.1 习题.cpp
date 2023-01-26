#include<iostream>
using namespace std;
struct sg{
	double m;
	double e;
};
double ev(double a,double b){
	return (a+b)*0.5;
}
int main(){
	sg xiaom;
	cin>>xiaom.m>>xiaom.e;
	cout<<ev(xiaom.m,xiaom.e);
	return 0;
}

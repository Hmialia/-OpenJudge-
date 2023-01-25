#include<iostream>
#include<cmath>
using namespace std;
void ss(long double a,long double b,long double c){
	if(a+b>c&&a+c>b&&b+c>a){
		long double p=(a+b+c)/2,s;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<s<<endl;
	}
	else cout<<"wrong!"<<endl;
}
int main(){
	long double a,b,c;
	cin>>a>>b>>c;
	ss(a,b,c);
	return 0;
}

#include<iostream>
using namespace std;

bool factor(int x,int&p,int&l){
	if(x>=0&&x<=20){
		p=x*x;
		l=p*x;
		return 1;
	}
	else return 0;
}

int main(){
	int x,p,l;
	cin>>x;
	if(factor(x,p,l))cout<<x<<" "<<p<<" "<<l;
	else cout<<"error";
	return 0;
}

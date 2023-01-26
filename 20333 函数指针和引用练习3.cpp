#include<iostream>
using namespace std;
int t=0;

int &fun(int a){
	t+=2*a;
	return t;
}

int main(){
	int x=1,y=2;
	x+=fun(x);
	y+=fun(y);
	cout<<x<<","<<y;
	return 0;
}

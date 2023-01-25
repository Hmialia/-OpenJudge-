#include<iostream>
#include<math.h>
using namespace std;

int main(){
	double x,y;
	cin>>x;
	if(x>=0&&x<=36)y=sqrt(x);
	else if(x>36&&x<=60)y=60;
	else if(x>60&&x<=100)y=x;
	if(y<59)cout<<"D";
	else if(y>=60&&y<=69)cout<<"C";
	else if(y>=70&&y<=89)cout<<"B";
	else if(y>90)cout<<"A";
	return 0;
}

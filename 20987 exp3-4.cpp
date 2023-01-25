#include<iostream>
using namespace std;
int main(){
	double x,y;
	cin>>x;
	if(x>2&&x<=10) y=x*(x+2);
	else if(x>-1&&x<=2) y=2*x;
	else if(x<=-1) y=x-1;
	cout<<y<<endl;
	return 0;
}

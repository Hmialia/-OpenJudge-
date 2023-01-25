#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x,y,z;
	x=y=z=1;
	x=x||y&&z;
	cout<<x<<","<<(x&&!y||z)<<endl;
	return 0;
} 

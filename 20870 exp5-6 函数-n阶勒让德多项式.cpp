#include<iostream>
using namespace std;
float pn(int n,float x)
{if (n==0) return 1;
	else if(n==1) return x;
	else if(n>1) return((2*n-1)*x*pn(n-1,x)-(n-1)*pn(n-2,x))/n;}
int main(){
	int n;
	float x;
	cout<<"please input n and x:"<<endl;
	cin>>n>>x;
	cout<<pn(n,x)<<endl;
	return 0;
}

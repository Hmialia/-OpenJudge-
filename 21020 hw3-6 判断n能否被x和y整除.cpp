#include<iostream>
using namespace std;
int main(){
	int n,x,y;
	cin>>n>>x>>y;
	if(n<=0||n>=30000||x<=0||y>=10000){cout<<"0 < n < 30000 ,  0 < x< y < 10000";}
	if(n%x==0&&n%y==0) cout<<"yes";
	else cout<<"no";
	return 0;
}

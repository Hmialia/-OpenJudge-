#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<1000||n>3000)cout<<"1000 <= Äê·Ý <= 3000";
	else if(n%400==0) cout<<"yes";
	else if(n%4==0&&n%100!=0) cout<<"yes";
	else cout<<"no";
	return 0;
}

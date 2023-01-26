#include <iostream>
using namespace std;

int fun(int n){
	if(n==1)return 1;
	else if(n==2)return 2;
	else return fun(n-1)+fun(n-2);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		cout<<fun(b)<<endl;
	}
	return 0;
}

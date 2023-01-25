#include<iostream>
using namespace std;
int main(){
	char a[30],b,c,n;
	cin>>a>>b>>c;
	n=sizeof(a);
	for(int i=0;i<n;i++)if(a[i]==b)a[i]=c;
	cout<<a;
	return 0;
}

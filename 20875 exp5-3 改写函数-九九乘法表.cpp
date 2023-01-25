#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int i,a,c,x;
	cin>>x;
	i=a=c=1;
	cout<<"  "<<"*";
	for(;i<=9;i++)cout<<setw(4)<<i;
	cout<<endl;
	for(;a<=41;a++)cout<<"-";
	cout<<endl;
	for(;c<=9;c++){
		cout<<"  "<<c;
		switch(x){
			case 1: for(int i=1;i<=9;i++)cout<<setw(4)<<i*c;break;
			case 2: for(int i=1;i<=c;i++)cout<<setw(4)<<i*c;break;
			case 3: {cout<<setw((c-1)*4)<<"";for(int i=c;i<=9;i++)cout<<setw(4)<<i*c;}break;
		}
		cout<<endl;
	}
}

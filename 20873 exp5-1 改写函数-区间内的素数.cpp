#include<iostream>
#include<iomanip>
using namespace std;
int s(int x){
	int y=1,i;
	for(i=2;i<x&&y!=0;i++) y=x%i;
	return i<x||x==1?0:1;
}
int main(){
	int a,b,i;
	cin>>a>>b;
	for(i=0;a<=b;a++){
		if(s(a)) {i++;cout<<setw(8)<<a;if(i>4&&i%5==0) cout<<endl;}
	}
}

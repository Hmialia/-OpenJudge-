#include<iostream>
using namespace std;
int ip(int a){
	int j=1;
	for(int i=2;i<a;i++)if(a%i==0)j=j+i;
	if(a==1||j!=a)return 0;
	return 1;
}
int main(){
	for(int i=1;i<1001;i++)if(ip(i))cout<<i<<endl;
}

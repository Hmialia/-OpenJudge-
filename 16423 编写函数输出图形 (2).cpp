#include<iostream>
using namespace std;
void fs(int n,char w){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<w;
		cout<<endl;}
}
int main(){
	int N[1000];
	char W[1000];
	int i=0;
	for(i;i<=1000;i++){cin>>N[i];if(N[i]<0)break;cin>>W[i];}
	for(int j=0;j<=i;j++)fs(N[j],W[j]);
	return 0;
}

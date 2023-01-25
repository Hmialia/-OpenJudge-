#include<iostream>;
using namespace std;
int j(int n){
	int c=1;
	for(int i=1;i<=n;i++)c=c*i;
	return c;
}
int c(int k,int r){
	return j(k)/(j(r)*j(k-r));
}
int main(){
	int K,R;
	cin>>K>>R;
	cout<<c(K,R)<<endl;
	return 0;
}

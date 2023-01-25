#include<iostream>;
using namespace std;
double f(double n){
	if(n==1)return 1;
	else return f(n-1)+n*n;
}
int main(){
	double n;
	cin>>n;
	cout<<f(n);
	return 0;
}

#include<iostream>
using namespace std;
const double p=3.14159;
double s1(double a,double b){return a*b;}
double s2(double a){return p*a*a;}
int main(){
	int n,x;
	double* c=new double[100];
	double a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==1){
			cin>>a>>b;
			c[i]=s1(a,b);
		}
		else{
			cin>>a;
			c[i]=s2(a);
		}
	}
	for(int j=0;j<n;j++)cout<<c[j]<<endl;
	delete []c;
	return 0;
}

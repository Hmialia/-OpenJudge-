#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x){return exp(x)/(1+x*x);}
const double eps=1e-8;
void fff(int n,double a,double b){
	double h,tn,t2n,in,i2n;
	const double eps=1e-8;
	h=b-a;
	t2n=i2n=h*(f(a)+f(b))/2;
	in=0;
	while(abs(i2n-in)>=eps){
		tn=t2n;
		in=i2n;
		double sigma=0.0;
		for(int k=0;k<n;k++){
			double x=a+(k+0.5)*h;
			sigma+=f(x);
		}
		t2n=(tn+h*sigma)/2.0;
		i2n=(4*t2n-tn)/3.0;
		n*=2;
		h/=2;
	}
	cout<<"the integral of f(x) from "<<a<<" to "<<b<<" is"<<endl
	<<setiosflags(ios::fixed)<<setprecision(8)<<setw(10)<<i2n<<endl;
}
int main(){
	int n=1;
	double a=0,b=1;
	fff(n,a,b);
	return 0;
}

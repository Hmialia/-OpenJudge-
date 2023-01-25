#include<iostream>
#include<iomanip>
#include<cmath> 
using namespace std;

double fd(double x)
{ double f1,f2;
	f1=2*x*x*x-4*x*x+3*x-6;
	f2=6*x*x-8*x+3;
	return (f1/f2);
}
const double eps=10e-6;

void newton(double x0,double e)
{double a=x0;
	double y=x0-fd(x0);
	while (abs(y-a)>e)
	{
		a=y;
		y=a-fd(a);
	}
	cout<<y<<endl;
}

int main()
{ double x=2.0;
	double e=eps; 
	newton(x,e);
} 

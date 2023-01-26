#include <iostream>
using namespace std;

class RMB{
protected:
	int yuan,jf;
public:
	RMB(){
		yuan=jf=0;
	}
	RMB(unsigned int d,unsigned int c){
		yuan=d+c/100;
		jf=c%100;
	}
	RMB(double a){
		yuan=a;
		jf=(a-yuan)*100.0+0.5;
	}
	RMB operator+ (RMB&s){
		unsigned int c=jf+s.jf;
		unsigned int d=yuan+s.yuan+c/100;
		c=c%100;
		return RMB(d,c);
	}
	RMB& operator ++(){
		if(++jf==100){
			jf=0;
			yuan++;
		}
		return *this;		
	}
	void display(){
		cout<<dou()<<endl;
	}
	double dou(){
		double b=yuan+jf/100.0;
		return b;
	}
	friend RMB operator*(const RMB &,double);
	friend RMB operator*(double,const RMB &);
};
RMB operator*(const RMB & a,double x){
	double b=a.yuan+a.jf/100.0;
	b=b*x;
	return RMB(b);
}
RMB operator*(double x,const RMB &a){
	return a*x;
}

int main()
{
	RMB d1(1,60);
	RMB d2(2,50);
	RMB d3(0,0);
	d3 = d1+d2;
	++d3;
	double x,y;
	cin>>x>>y;
	RMB d4,d5;
	d4 = x*d3; d4.display();
	d5 = d3*y; d5.display();
	return 0;
}

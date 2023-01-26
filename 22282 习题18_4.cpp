#include<iostream>
using namespace std;

class RMB{
protected:
	int yuan,jf;
	double dou(){
		double b=yuan+jf/100.0;
		return b;
	}
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
	RMB operator+ (const RMB&s){
		unsigned int c=jf+s.jf;
		unsigned int d=yuan+s.yuan+c/100;
		c=c%100;
		return RMB(d,c);
	}
	RMB operator- (const RMB&s){
		double c=yuan-s.yuan+(jf-s.jf)/100.0;
		if(c<0)cout<<"error"<<endl;
		return RMB(c);
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
	friend RMB operator*(const RMB &,double);
	friend RMB operator*(double,const RMB &);
	RMB& operator+=(const RMB& b){
		*this=*this+b;
		return *this;
	}
	RMB& operator+=(double b){
		*this=*this+RMB(b);
		return *this;
	}
	RMB& operator-=(const RMB& b){
		*this=*this-b;
		return *this;
	}
	RMB& operator-=(double b){
		*this=*this-RMB(b);
		return *this;
	}
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
	RMB d3;
	double db;
	cin>>db;
	d3 += d2; 
	d3 += db; d3.display();
	d3 -= d1; 
	d3 -= db; d3.display(); 
	return 0;
}

#include<iostream>
using namespace std;

class Complex{
protected:
	double shi, xv;
public:
	Complex(){}
	Complex(double a,double b){
		shi=a;xv=b;       	
	}
	void print(){
		cout<<shi<<"+i"<<xv<<endl;	
	}
	friend Complex operator + (Complex&,Complex&);
	friend Complex operator - (Complex&,Complex&);
	friend Complex operator + (float,Complex&);
	friend Complex operator + (Complex&,float);
};

Complex operator + (Complex& a,Complex& b){
	Complex c;
	c.shi=a.shi+b.shi;c.xv=a.xv+b.xv;
	return c;	
}
Complex operator - (Complex& a,Complex& b){
	Complex c;
	c.shi=a.shi-b.shi;c.xv=a.xv-b.xv;
	return c;	
}
Complex operator + (float a,Complex&b){
	Complex c;
	c.shi=a+b.shi;c.xv=b.xv;
	return c;
}
Complex operator + (Complex& a,float b){
	Complex c;
	c.shi=a.shi+b;c.xv=a.xv;
	return c;	
}

int main()
{
	Complex a(2,5),b(7,8),c(0,0);
	c = a + b;
	c = 4.1 + a;
	c = b+5.6;
	double x,y;
	cin>>x>>y;
	Complex z(x,y);
	c = c-z;
	c.print();
	return 0;
}

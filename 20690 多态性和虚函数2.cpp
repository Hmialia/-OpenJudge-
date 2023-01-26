#include<iostream>
using namespace std;

class shape{
public:
	shape(){}
	virtual ~shape(){};
	virtual double GetArea()=0; 
}; 

class Rectangle:public shape{
protected:
	double a,b;
public:
	Rectangle(){}
	Rectangle(double aa,double bb){
		a=aa,b=bb;
	}
	double GetArea(){
		return a*b;
	}
	~Rectangle(){}
};

class Circle:public shape{
protected:
	double r;
public:
	Circle(){}
	Circle(double rr){
		r=rr;
	}
	double GetArea(){
		return 3.1415*r*r;
	}
	~Circle(){}
};

int main(){
	Rectangle* rec=new Rectangle(5,12);
	Circle* cir=new Circle(4);
	cout<<rec->GetArea()<<endl<<cir->GetArea();
	delete rec;
	delete cir;
	return 0;
}

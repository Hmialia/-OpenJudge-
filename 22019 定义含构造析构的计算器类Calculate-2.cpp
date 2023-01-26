#include<iostream>
using namespace std;
class calcuate2{
private:
	double a,b;
public:
	void SetAB(double x,double y){
		a=x;b=y;
	}
	double GetAdd(){
		return a+b;
	}
	double GetMimus(){
		return a-b;
	}
	double GetMultiply(){
		return a*b;
	}
	double Getdivide(){
		return a/b;
	}
	double GetA(){
		return a;
	}
	double GetB(){
		return b;
	}
	calcuate2(){
		a=b=0;
	}
	calcuate2(double x,double y){
		a=x;b=y;
	}
	calcuate2(calcuate2 & c){
		a=c.GetA();b=c.GetB();
	}
	~calcuate2(){
		cout<<"Destructure"<<a<<","<<b<<endl;
	}
};
int main(){
	calcuate2 cal1;
	calcuate2 cal2(1.1,2.2);
	calcuate2 cal3(cal2);
	cout<<cal1.GetAdd()<<endl
	<<cal1.GetMimus()<<endl
	<<cal1.GetMultiply()<<endl
	
	<<cal2.GetAdd()<<endl
	<<cal2.GetMimus()<<endl
	<<cal2.GetMultiply()<<endl
	<<cal2.Getdivide()<<endl
	
	<<cal3.GetAdd()<<endl
	<<cal3.GetMimus()<<endl
	<<cal3.GetMultiply()<<endl
	<<cal3.Getdivide()<<endl;
}

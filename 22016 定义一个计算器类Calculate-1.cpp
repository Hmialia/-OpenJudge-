#include<iostream>
using namespace std;
class calcuate{
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
};
int main(){
	double a,b;
	cin>>a>>b;
	calcuate cal;
	cal.SetAB(a,b);
	cout<<cal.GetAdd()<<endl
	<<cal.GetMimus()<<endl
	<<cal.GetMultiply()<<endl
	<<cal.Getdivide()<<endl;
	return 0;
}

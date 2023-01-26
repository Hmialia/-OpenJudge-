#include<iostream>
using namespace std;

template<class T>
class calculator{
private:
	T x,y;
public:
	calculator(){}
	calculator(T a,T b){x=a;y=b;}
	T GetAdd(){return x+y;}
	T GetMinus(){return x-y;}
	T GetDivi(){return x/y;}
	T GetMupli(){return x*y;}
}; 

int main(){
	calculator <double> m(1.1,2.2);
	calculator <int> n(1,2);
	cout<<m.GetAdd()<<endl
	<<m.GetMinus()<<endl
	<<m.GetMupli()<<endl
	<<m.GetDivi()<<endl
	<<n.GetAdd()<<endl
	<<n.GetMinus()<<endl
	<<n.GetMupli()<<endl
	<<n.GetDivi()<<endl;
	return 0;
}

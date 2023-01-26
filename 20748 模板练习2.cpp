#include<iostream>
using namespace std;

template<class T>
class calculator{
private:
	T x,y;
public:
	calculator(){}
	calculator(T,T);
	T GetAdd();
	T GetMinus();
	T GetDivi();
	T GetMupli();
}; 

template<class T>
calculator<T>::calculator(T a,T b){x=a;y=b;}

template<class T>
T calculator<T>::GetAdd(){return x+y;}

template<class T>
T calculator<T>::GetMinus(){return x-y;}

template<class T>
T calculator<T>::GetDivi(){return x/y;}

template<class T>
T calculator<T>::GetMupli(){return x*y;}

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

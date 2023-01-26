#include<iostream>
using namespace std;
class MyClass{
private:
	int i;
public:
	MyClass(){
		cout<<"Constructing normally."<<endl;	
	}
	MyClass(int m){
		i=m;
		cout<<"Constructing with a number-"<<i<<endl;	
	}
	~MyClass(){
		cout<<"Destructing."<<endl;	
	}
	void Display(){
		cout<<"Display a number-"<<i<<endl;
	}
};
int main(){
	MyClass obj1;
	MyClass obj2(20);
	obj2.Display();
	return 0;	
}

#include<iostream>
using namespace std;
class cc{
public:
	int value;
	static int staticV;
	cc(){}
	cc(int a){
		value=a;
		staticV++;
	}
	~cc(){
		staticV--;
	}
};
int cc::staticV=0;
int main(){
	cc * v1=new cc(5);
	cc * v2=new cc(80);
	cc * v3=new cc(20);
	cout<<v1->value<<endl
	<<v2->value<<endl
	<<v3->value<<endl
	<<cc::staticV<<endl;
	delete v1;
	cout<<cc::staticV<<endl;
	delete v2;
	cout<<cc::staticV<<endl;
	delete v3;
	cout<<cc::staticV<<endl;
	return 0;
}

#include<iostream>
using namespace std;
class cc{
private:
	int value;
	static int staticV;
public:
	cc(){staticV++;}
	cc(int a){
		value=a;
		staticV++;
	}
	~cc(){
		staticV--;
	}
	int Get(){
		return value;
	}
	static int GetStatic(){
		return staticV;
	}
};
int cc::staticV=0;
int main(){
	cc * v1=new cc(5);
	cc * v2=new cc(80);
	cc * v3=new cc(20);
	cout<<v1->Get()<<endl
	<<v2->Get()<<endl
	<<v3->Get()<<endl
	<<v1->GetStatic()<<endl;
	delete v1;
	cout<<v2->GetStatic()<<endl;
	delete v2;
	cout<<v3->GetStatic()<<endl;
	delete v3;
	cout<<cc::GetStatic()<<endl;
	return 0;
}

#include<iostream>
using namespace std;
class Animal{
public:
	void Set(int v);
	void Set(int v, int w);
	void show(){ 
		cout<<"itsWeight="<<itsWeight<<endl
		<<"itsAge="<<itsAge<<endl;
	}
protected:
	int itsWeight;
	int itsAge;
};
void Animal::Set(int v){
	itsWeight=v;
}
void Animal::Set(int v,int w){
	itsWeight=v;itsAge=w;
}
void SetValue(Animal&a, int t){
	a.Set(t);
}
void SetValue(Animal&a, int b,int c){
	a.Set(b,c);
}

int main(){
	Animal peppy;
	SetValue(peppy, 5);
	peppy.show();
	SetValue(peppy,7,9);
	peppy.show();
}

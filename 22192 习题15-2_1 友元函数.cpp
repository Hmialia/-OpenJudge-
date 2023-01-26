#include<iostream>

using namespace std;

class Animal{
protected:
	int itsWeight;
	int itsAge;
public:
	friend void SetValue(Animal&, int);
	friend void SetValue(Animal&, int, int);
	void show(){
		cout<<"itsWeight="<<itsWeight<<endl
		<<"itsAge="<<itsAge<<endl;
	}
};

void SetValue(Animal&a, int t){
	a.itsWeight=t;
	a.itsAge=0;
}
void SetValue(Animal&a, int b,int c){
	a.itsWeight=b;
	a.itsAge=c;
}
int main(){
	
	Animal peppy;
	
	SetValue(peppy, 5);
	
	peppy.show();
	
	SetValue(peppy,7,9);
	
	peppy.show();
	
}

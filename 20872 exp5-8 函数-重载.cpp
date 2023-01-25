#include<iostream>
using namespace std;
void display(double d){cout<<"double: "<<d<<endl;}
void display(int i){cout<<"int: "<<i<<endl;}
void display(char c){cout<<"char: "<<c<<endl;}
int main(){
	double a;
	float b;
	int c;
	char d;
	short e;
	cout<<"double float int char short:"<<endl;
	cin>>a>>b>>c>>d>>e;
	display(a);
	display(b);
	display(c);
	display(d);
	display(e);
	return 0;
}

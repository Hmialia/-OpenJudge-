#include<iostream>
using namespace std;

class RMB{
public:
	RMB(unsigned int d, unsigned int c);
	RMB operator+(RMB&);
	void display(){ cout<<(yuan + jf / 100.0)<<endl; }
protected:
	unsigned int yuan;
	unsigned int jf;
};

RMB::RMB(unsigned int d, unsigned int c)
{
	yuan = d + c/100;
	jf = c % 100;
}
RMB RMB::operator+(RMB& a){
	RMB c(yuan+a.yuan,jf+a.jf);
	return c;
} 
int main()
{
	RMB d1(1, 50);
	RMB d2(2, 80);
	RMB d3(0, 0);
	d3 = d1 + d2;
	d3.display();
}

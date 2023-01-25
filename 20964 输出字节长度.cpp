#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	cout<<left
	<<setw(23)<<"size of char"<<sizeof(char)<<" byte"<<endl
	<<setw(23)<<"size of unsigned char"<<sizeof(unsigned char)<<" byte"<<endl
	<<setw(23)<<"size of signed char"<<sizeof(signed char)<<" byte"<<endl
	<<setw(23)<<"size of int"<<sizeof(int)<<" byte"<<endl
	<<setw(23)<<"size of unsigned"<<sizeof(unsigned)<<" byte"<<endl
	<<setw(23)<<"size of signed"<<sizeof(signed)<<" byte"<<endl
	<<setw(23)<<"size of short"<<sizeof(short)<<" byte"<<endl
	<<setw(23)<<"size of unsigned short"<<sizeof(unsigned short)<<" byte"<<endl
	<<setw(23)<<"size of float"<<sizeof(float)<<" byte"<<endl
	<<setw(23)<<"size of double"<<sizeof(double)<<" byte"<<endl
	<<setw(23)<<"size of long double"<<sizeof(long double)<<" byte"<<endl;
}

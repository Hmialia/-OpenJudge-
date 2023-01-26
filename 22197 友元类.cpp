#include<iostream>
using namespace std;

class MyDate;
class MyTime{
private:
	int hour,min,sec;
public:
	friend class MyDate;
	MyTime(int a,int b,int c){
		hour=a;
		min=b;
		sec=c;
	}
};

class MyDate{
private:
	int year,mon,day;
public:
	MyDate(int a,int b,int c){
		year=a;
		mon=b;
		day=c;
	}
	void Display(MyTime&c){
		cout<<year<<"/"<<mon<<"/"<<day<<" "
		<<c.hour<<":"<<c.min<<":"<<c.sec;
	}
};

int main(){
	MyTime t(10,30,45);
	MyDate d(2021,4,20);
	d.Display(t);
}

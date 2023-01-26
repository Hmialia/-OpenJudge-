#include <iostream>
using namespace std;
#include<string.h>

class Employee
{
protected:
	int num;
	string name;
	float basicSalary;
public:
	Employee(int n,string nam,float b)
	{
		num=n;
		name=nam;
		basicSalary=b;
	}		
	void show()
	{
		cout<<num<<","<<name<<","<<basicSalary<<endl;
	}	
};
class Manager:public Employee{
public:
	Manager(int n,string nam,float b):Employee(n,nam,b){}
};

class Technician:public Employee{
private:
	float yuezi;
public:
	Technician(int n,string nam,float b,int c):Employee(n,nam,b){
		yuezi=basicSalary+100*c;
	}
	void show(){
		cout<<num<<","<<name<<","<<basicSalary<<endl
		<<yuezi<<endl;
	}
};

class Salesman:public Employee{
private:
	float yuezi;
public:
	Salesman(int n,string nam,float b,float c):Employee(n,nam,b){
		yuezi=basicSalary+0.04*c;
	}
	void show(){
		cout<<num<<","<<name<<","<<basicSalary<<endl
		<<yuezi<<endl;
	}
};
int main()
{
	Manager m(1000,"Wang",8000);
	m.show();	
	Technician t(1001,"Zhang",3000,90);
	t.show();
	Salesman s(1002,"Li",2000,90000);
	s.show();
	return 0;
}

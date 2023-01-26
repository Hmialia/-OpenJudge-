#include<iostream>
using namespace std;
#include<string.h>
class ChildTicket{
public:
	ChildTicket(){
		cout<<"Ticket for Children!"<<endl;
	}
	void Print(){
		return;
	}
};

class Ticket{
protected:
	char name[15];
	int age;
	char sex;
public:
	Ticket(){
		cout<<"Ticket for old people!"<<endl;
	}
	Ticket(char n[15],char s,int a){
		strcpy(name,n);
		sex=s;
		age=a;
		cout<<"Ticket for "<<name<<","<<sex<<","<<age<<endl;
	}
	void Print(){
		return;
	}
};
int main()
{
	ChildTicket a;
	a.Print();
	Ticket b;
	char *name=new char[20];
	char sex;
	int age;
	cin>>name>>sex>>age; 
	Ticket c(name,sex,age);
	c.Print();
	
	return 0;
}

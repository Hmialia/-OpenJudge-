#include<iostream>
#include<string.h>
using namespace std;
class Employee{
protected:
	char name[20];
	char dress[20];
	char city[20];
	char province[10];
	char code[10];
public:
	Employee(){};
	Employee(char n[20],char d[20],char ci[20],char p[10],char co[10]){
		strcpy(name,n);
		strcpy(dress,d);
		strcpy(city,ci);
		strcpy(province,p);
		strcpy(code,co);	
	}
	void ChangeName(char n[20]){
		strcpy(name,n);	
	}
	void Display(){
		cout<<name<<endl
		<<dress<<" "<<city<<endl
		<<province<<" "<<code<<endl;
	}
};

int main(){
	Employee em("Mark Brooks","5 West St.","Revere","CA","12290");
	
	em.Display();
	em.ChangeName("Richard Voss");
	em.Display();
}

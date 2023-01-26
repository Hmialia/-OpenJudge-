#include<iostream>
#include<string.h>
using namespace std;
class Name{
protected:
	char firstN[20];
	char nextN[20];
public:
	Name(){};
	Name(char*p){
		int i=0;
		for(;(*p)!=' ';p++,i++){
			firstN[i]=*p;
		}
		firstN[i]='\0';
		p++;
		for(i=0;(*p)!='\0';p++,i++){
			nextN[i]=*p;
		}
		nextN[i]='\0';
	}
	void Display(){
		cout
		<<firstN<<" "
		<<nextN<<endl;
	}
};
class Employee{
protected:
	Name nam;
	char dress[20];
	char city[20];
	char province[10];
	char code[10];
public:
	Employee(){};
	Employee(char n[20],char d[20],char ci[20],char p[10],char co[10]){
		Name nbm(n);
		nam=nbm;
		strcpy(dress,d);
		strcpy(city,ci);
		strcpy(province,p);
		strcpy(code,co);	
	}
	void ChangeName(char n[20]){
		Name nbm(n);
		nam=nbm;
	}
	void Display(){
		nam.Display();
		cout<<dress<<" "<<city<<endl
		<<province<<" "<<code<<endl;
	}
};

int main(){
	Employee em("Mark Brooks","5 West St.","Revere","CA","12290");
	em.Display();
	em.ChangeName("Richard Voss");
	em.Display();
}

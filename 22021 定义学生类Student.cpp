#include<iostream>
#include<string.h>
using namespace std;
class Student{
private:
	char name[10];
	int id;
public:
	Student(){
		strcpy(name,"NULL");
		id=0;
		cout<<"No-parameter Construction"<<endl;	
	}
	Student(char n[10],int a){
		strcpy(name,n);
		id=a;
		cout<<"Construction"<<endl;	
	}
	~Student(){
		cout<<"Destruction"<<endl;	
	}
	void SetInfor(char n[10],int a){
		strcpy(name,n);
		id=a;	
	}
	char* GetName(){
		return name;	
	}
	int GetID(){
		return id;	
	}
	void print(){
		cout<<name<<endl<<id<<endl;	
	}
};
int main(){
	Student stu1("zhangsan",1001);
	stu1.print();
	Student stu2;
	stu2.print();
	stu2.SetInfor("Lisi",1002);
	stu2.print();
	return 0;	
}

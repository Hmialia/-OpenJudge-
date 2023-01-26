#include<iostream>
using namespace std;

class Teacher{
protected:
	int BasicWage;
	int ClassWage;
	int Class;
public:
	Teacher(int a,int b,int c){
		BasicWage=a;ClassWage=b;Class=c;
	}
	int GetWage(){
		return BasicWage+ClassWage*Class;
	}
	virtual ~Teacher(){} 	
};

class Professor:public Teacher{
public:
	Professor():Teacher(5000,50,200){}
	virtual ~Professor(){}
};

class AssistantProfessor:public Teacher{
public:
	AssistantProfessor():Teacher(3000,30,250){}
	virtual ~AssistantProfessor(){}
};

class Lecturer:public Teacher{
public:
	Lecturer():Teacher(2000,20,100){}
	virtual ~Lecturer(){}
};

int main(){
	Professor* pro=new Professor();
	AssistantProfessor* as=new AssistantProfessor();
	Lecturer* lec=new Lecturer();
	cout<<pro->GetWage()<<endl
	<<as->GetWage()<<endl
	<<lec->GetWage()<<endl;
	delete lec;
	delete as;
	delete pro;
	return 0;
}

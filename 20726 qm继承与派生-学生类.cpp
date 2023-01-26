#include<iostream>
using namespace std;
#include<string.h>
class Student
{
	char *name;
	char *stunum;
	char *uniname;
public:
	Student();
	Student(char *pn, char* ps, char* pu);
	void print();
};

Student::Student(){}
Student::Student(char *pn,char* ps,char* pu){
	//	strcpy(name,pn);strcpy(stunum,ps);strcpy(uniname,pu);
	name=pn;stunum=ps;uniname=pu;
}

void Student::print(){
	cout<<"name="<<name<<endl
	<<"StuNum="<<stunum<<endl
	<<"universty_name="<<uniname<<endl;
}

class GraStudent:public Student{
private:
	char name[20];
	char stunum[20];
	char uniname[20];
	char special[20];
	char directorname[20];
public:
	GraStudent(){}
	GraStudent(const char pn[20],const char ps[20],const char pu[20],const char d[20],const char e[20]){
		strcpy(name,pn);strcpy(stunum,ps);strcpy(uniname,pu);
		strcpy(special,d);strcpy(directorname,e);
	}
	void print(){
		cout<<"name="<<name<<endl
		<<"StuNum="<<stunum<<endl
		<<"universty_name="<<uniname<<endl
		<<"special is "<<special<<endl
		<<"director is "<<directorname<<endl;
	}
};


int main()
{
	Student stu1("Li","1600141","CUC");
	stu1.print();
	GraStudent gstu("Wang","1600240","CUC","Computer","Zhang");
	gstu.print();
	return 0;
}

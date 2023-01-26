#include<iostream>
#include<string.h>
using namespace std;
static int sum_score=0, count=0;

class Student{
private:
	char name[10];
	int score;
public:
	friend void sum(Student&);
	Student(char n[10],int a){
		score=a;
		strcpy(name,n);
	}		
};

void sum(Student&stu){
	count++;
	sum_score+=stu.score;
}
double aver(){
	double a=sum_score;
	double b=count;
	return a/b; 
}

int main(){
	Student stu[5] ={Student("Ma",89),Student("Hu",90),Student("LU",95),
		Student("Li",88),Student("Gao",75)};
	for(int i=0;i<5;i++)
		sum(stu[i]);
	cout<<sum_score<<"," <<count<<endl;
	cout<<"Average="<<aver()<<endl;
}

#include<iostream>
#include<string.h>
using namespace std;

class Student{
private:
	char name[10];
	int score;
	static int count;
	static int sum_score;
public:
	void sum(){
		count++;
		sum_score+=score;
	}
	static double aver(){
		double a=sum_score;
		double b=count;
		return a/b; 
	}
	Student(char n[10],int a){
		score=a;
		strcpy(name,n);
	}		
};
int Student::sum_score=0;
int Student::count=0;

int main(){
	Student stu[5] ={Student("Ma",89),Student("Hu",90),Student("LU",95),
		Student("Li",88),Student("Gao",75)};
	for(int i=0;i<5;i++)
		stu[i].sum();
	cout<<"Average="<<Student::aver()<<endl;
}

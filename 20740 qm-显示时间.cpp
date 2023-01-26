#include <iostream>
using namespace std;
class Time;

class Date{
protected:
	int year,month,day;
public:
	Date(){}
	Date(int a,int b,int c){
		year=a;month=b;day=c;
	}
	friend class Time;
}; 

class Time{
protected:
	int hour,minute,second;
public:
	Time(){}
	Time(int a,int b,int c){
		hour=a;minute=b;second=c;
	}
	void display(){
		cout<<hour<<":"<<minute<<":"<<second<<endl;
	}
	void display(const Date& a){
		cout<<a.month<<"/"<<a.day<<"/"<<a.year<<endl
		<<hour<<":"<<minute<<":"<<second<<endl;
	}
};

int main()
{
	int year,month,day;
	int hour,minute,second;
	cin>>year>>month>>day;
	cin>>hour>>minute>>second;
	Time t1(hour,minute,second);
	Date d1(year,month,day);
	t1.display(d1);
	return 0;
}

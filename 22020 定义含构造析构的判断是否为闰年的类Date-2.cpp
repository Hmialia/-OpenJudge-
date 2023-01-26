#include<iostream>
using namespace std;
class date_2{
private:
	int year,month,day;
public:
	void SetDate(int y,int m,int d){
		year=y;month=m;day=d;
	}
	bool IsLeapYear(){
		return(year%400==0||(year%4==0&&year%100!=0));
	}
	void Display(){
		cout<<year<<"/"
		<<month<<"/"
		<<day<<"-"
		<<(year%400==0||(year%4==0&&year%100!=0))<<endl;
	}
	date_2(){
		year=0;month=0;day=0;
	} 
	date_2(int y,int m,int d){
		year=y;month=m;day=d;
	}
	date_2(date_2 & a){
		year=a.year;month=a.month;day=a.day;
	}
};
int main(){
	date_2 date0;
	date0.Display();
	date_2 date1(2019,1,5);
	date1.Display();
	date_2 date2(date1);
	date1.Display();
	return 0;
}

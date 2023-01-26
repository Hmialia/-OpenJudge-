#include<iostream>
using namespace std;
class date_1{
private:
	int year,month,day;
public:
	void SetDate(int y,int m,int d){
		year=y;month=m;day=d;
	}
	bool IsLeapYear(){
		return(year%400==0||(year%4==0&&year%100!=0));
	}
};
int main(){
	date_1 date1,date2;
	date_1* p=&date2;
	int y1,m1,d1,y2,m2,d2;
	cin>>y1>>m1>>d1>>y2>>m2>>d2;
	date1.SetDate(y1,m1,d1);
	p->SetDate(y2,m2,d2);
	cout<<date1.IsLeapYear()<<endl
	<<p->IsLeapYear();
	return 0;
}

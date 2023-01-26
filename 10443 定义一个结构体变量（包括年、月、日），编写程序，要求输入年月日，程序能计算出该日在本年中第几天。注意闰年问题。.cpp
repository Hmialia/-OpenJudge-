#include<iostream>
using namespace std;
struct date{
	int year;
	int mon;
	int day;
};
int number(date oneday){
	int n=oneday.day;
	int d=28;
	if(oneday.year%400==0)d=29;
	else if(oneday.year%100!=0&&oneday.year%4==0)d=29;
	switch(oneday.mon){
		case 12:n+=30;
		case 11:n+=31;
		case 10:n+=30;
		case 9:n+=31;
		case 8:n+=31;
		case 7:n+=30;
		case 6:n+=31;
		case 5:n+=30;
		case 4:n+=31;
		case 3:n+=d;
		case 2:n+=31;
	}
	return n;
}
int main(){
	date oneday;
	cin>>oneday.year>>oneday.mon>>oneday.day;
	cout<<"¸ÃÈÕÔÚ±¾ÄêÖÐÊÇµÚ"<<number(oneday)<<"Ìì";
	return 0;
}

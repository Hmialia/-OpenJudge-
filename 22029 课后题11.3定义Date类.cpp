#include<iostream>
using namespace std;
class Date{
private:
	int year,mon,day;
public:
	void SetDate(int a,int b,int c){
		year=a; mon=b; day=c;
	}
	void DisplayDate(){
		cout<<day<<"/"<<mon<<"/"<<year<<endl;
	}
	void PlusDay(){
		if(day<27)day++;
		else if(mon==1||mon==3||mon==5||mon==7||mon==8||mon==10||mon==12){
			if(day<31)day++;
			else{
				day=1;
				if(mon==12){
					mon=1;
					year++;
				}
				else mon++;
			}
		}
		else if(mon==4||mon==6||mon==9||mon==11){
			if(day<30)day++;
			else{
				day=1;
				mon++;
			}
		}
		else if(year%400==0||(year%100!=0&&year%4==0)){
			if(day<28)day++;
			else{
				day=1;
				mon++;
			}
		}
		else{
			day=1;
			mon++;
		}
	}
};
int main(){
	Date da1,da2;
	int n1,y1,r1,n2,y2,r2;
	cin>>n1>>y1>>r1>>n2>>y2>>r2;
	da1.SetDate(n1,y1,r1);
	da2.SetDate(n2,y2,r2);
	da1.DisplayDate();
	da1.PlusDay();
	da1.DisplayDate();
	da2.DisplayDate();
	return 0;
}

#include<iostream>
using namespace std;
class Time{
private:
	int h,m,s;
public:
	void SetTime(int a,int b,int c){
		h=a;m=b;s=c;
	}
	void DisplayTime(){
		if(h<10)cout<<"0";
		cout<<h<<":"<<m<<":"<<s<<endl;
	}
};
int main(){
	Time tim;
	tim.SetTime(3,32,48);
	tim.DisplayTime();
	return 0;
}

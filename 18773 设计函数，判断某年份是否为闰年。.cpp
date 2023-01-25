#include<iostream>
using namespace std;
bool IsLeapYear(int y){
	if(y%400==0)return 1;
	else if(y%100==0)return 0;
	else if(y%4==0)return 1;
	else return 0;
}
int main(){
	int n;
	cin>>n;
	if(IsLeapYear(n))cout<<"Is the leap year"<<endl;
	else cout<<"Not leap year"<<endl;
	return 0;
}

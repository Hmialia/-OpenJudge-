#include<iostream>
using namespace std;
int main(){
	int g;
	cin>>g;
	if(g>100||g<0||g==90) cout<<"error"; 
	else if(g>90) cout<<"A";
	else if(g>=80) cout<<"B";
	else if(g>=70) cout<<"C";
	else if(g>=60) cout<<"D";
	else if(g>=0) cout<<"E";
	cout<<"."<<endl;
	return 0;
} 

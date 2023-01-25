#include<iostream>
using namespace std;
int main(){
	int x,t3,t5,t7;
	cin>>x;
	t3=x%3,t5=x%5,t7=x%7;
	if(t3==0&&t5==0&&t7==0) cout<<"divided by 3,5,7."<<endl;
	else if(t3==0&&t5==0) cout<<"divided by 3,5."<<endl;
	else if(t3==0&&t7==0) cout<<"divided by 3,7."<<endl;
	else if(t7==0&&t5==0) cout<<"divided by 5,7."<<endl;
	else if(t3==0) cout<<"only divided by 3."<<endl;
	else if(t5==0) cout<<"only divided by 5."<<endl;
	else if(t7==0) cout<<"only divided by 7."<<endl;
	else cout<<"not divided by 3,5,7."<<endl;
	return 0;
} 

#include<iostream>
using namespace std;
int fb(int n)
{if(n==1||n==2) return 1;
	else return fb(n-1)+fb(n-2);}
int main(){
	int n;
	cout<<"please input a number:"<<endl;
	cin>>n;
	cout<<fb(n);
	return 0;
}

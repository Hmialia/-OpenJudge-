#include<iostream>
using namespace std;
#include<string.h>

class Swap{
public:
	int n1,n2;
	double d1,d2;
	char a1[10],a2[10];
	void swap(int& n1,int& n2){
		int temp=n1;
		n1=n2;
		n2=temp;
	}
	void swap(double& n1,double& n2){
		double temp=n1;
		n1=n2;
		n2=temp;
	}
	void swap(char* n1,char* n2){
		char temp[10];
		strcpy(temp,n1);
		strcpy(n1,n2);
		strcpy(n2,temp);
	}
};
int main()
{
	Swap a;
	
	cin>>a.n1>>a.n2;
	a.swap(a.n1,a.n2);
	cout<<a.n1<<","<<a.n2<<endl; 
	
	cin>>a.d1>>a.d2;
	
	a.swap(a.d1,a.d2);  
	cout<<a.d1<<","<<a.d2<<endl;  
	
	cin>>a.a1>>a.a2;
	
	a.swap(a.a1,a.a2);
	cout<<a.a1<<","<<a.a2<<endl;
	return 0;	
}

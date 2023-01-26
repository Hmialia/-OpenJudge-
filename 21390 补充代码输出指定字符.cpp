#include<stdio.h>
#include<iostream>
using namespace std;
void print3rd(char (*s)[10])
{
	for(int i=0;i<3;i++){
		cout<<s[i][2]<<endl;
	}
}
int main() 
{
	char a[3][10];
	int i;
	char (*ps)[10]=a;
	for(i=0;i<3;i++)
		gets(a[i]);
	print3rd(ps);
	return 0;
}

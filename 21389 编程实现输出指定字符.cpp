#include<stdio.h>
#include<iostream>
using namespace std;
void print3rd(char**s)
{
	int i=0;while(i<3)cout<<s[i++][2]<<endl;
}
int main() 
{
	char a[10],b[10],c[10];
	char *ps[3]={a,b,c};	
	gets(a);
	gets(b);
	gets(c);
	print3rd(ps);
	return 0;
}

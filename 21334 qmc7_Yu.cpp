#include <iostream>
using namespace std;
int main( )
{  void sort(int *p,int n);                  
	int a[10], i;
	for(i=0;i<10;i++)                               
		cin>>a[i];
	sort(a,10);                              
	for(i=0;i<10;i++)                               
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
void sort(int *p,int n){
	int t;
	for(int j=0;j<n;j++){
		for(int i=0;i<n-1;i++){
			if(p[i]>p[i+1]){
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=t;
			}
		}
	}
}

#include<iostream>
using namespace std;
int main(){
	int A[]={34,91,83,56,29,93,56,12,88,72},m=A[0],j=0;
	for(int i=1;i<10;i++)if(m>A[i]){m=A[i];j=i;}
	cout<<m<<endl<<j;
}

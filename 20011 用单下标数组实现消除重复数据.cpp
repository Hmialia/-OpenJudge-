#include<iostream>
using namespace std;
int main(){
	int a[20];
	int b[20];
	for(int i=0;i<20;i++)cin>>a[i];
	b[0]=a[0];
	int k=1,j=1;
	for(j;j<20;j++){
		int c=0;
		for(int l=0;l<k;l++){
			c=c||(b[l]==a[j]);
		}
		if(!c){
			b[k]=a[j];
			k++;
		}
	}
	for(int r=0;r<k;r++)cout<<b[r]<<" ";
	return 0;
}

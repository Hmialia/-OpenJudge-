#include<iostream>
using namespace std;
int main(){
	int a[10]={34,91,83,56,29,93,56,12,88,72};
	int m=a[0],x=0;
	for(int i=1;i<10;i++){
		if(a[i]<m){
			m=a[i];
			x=i;
		}
	}
	cout<<m<<" "<<x;
	return 0;
}

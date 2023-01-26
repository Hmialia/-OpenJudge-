#include<iostream>
using namespace std;
const int size=10;

void findmax(int*a,int l,int&n){
	int m=a[0];
	for(int i=1;i<l;i++){
		if(a[i]>m){
			m=a[i];
			n=i;
		}
	}
}

int main(){
	int a[size];
	int n=0;
	cout<<"please input "<<size<<"datas:\n";
	for(int i=0; i<size; i++)
		cin>>a[i];
	findmax(a,size,n);
	cout<<"the maximum is "<<a[n]<<endl
	<<"It's index is "<<n<<endl;
}

#include<iostream>
using namespace std;
int vals[10];
int error = -1;
//定义int&put(int n)和int get(int n)
int &put(int n){
	if(n<0||n>9){
		cout<<"range error in put() value."<<endl;
		return error;
	}
	else return vals[n];
}

int &get(int n){
	return vals[n];
}

int main()
{
	int n;
	cin>>n;
	if(put(n)==-1)
		return 0;
	cin>>put(n);
	cout<<get(n)<<endl;
	return 0; 
}

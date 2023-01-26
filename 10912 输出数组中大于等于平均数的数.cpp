#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int as[n];
	int add=0;
	for(int i=0;i<n;i++){
		cin>>as[i];
		add+=as[i];
	}
	double ave=(double)add/(double)n;
	for(int i=0;i<n;i++){
		if(as[i]>=ave)cout<<as[i]<<" ";
	}	
	cout<<endl;
	return 0;
}

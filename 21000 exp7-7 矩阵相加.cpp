#include<iostream>
using namespace std;
int main(){
	int a[3][3]={5,7,8,2,-2,4,1,1,1};
	int b[3][3]={4,-2,3,3,9,4,8,-1,2};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<a[i][j]+b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

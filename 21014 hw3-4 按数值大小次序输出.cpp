#include<iostream>
using namespace std;
int main(){
	float x,y;
	cin>>x>>y;
	cout<<(x<y?x:y)<<" "<<(x<y?y:x);
	return 0;
}

#include<iostream>
using namespace std;
class arraymax{
private:
	int n;
	int array[10];
	int max;
public:
	void setv(int);
	void maxv();
	void showv();
};
void arraymax::setv(int nn){
	n=nn;
	for(int i=0;i<n;i++)cin>>array[i];
}
void arraymax::maxv(){
	max=array[0];
	for(int i=1;i<n;i++)if(array[i]>max)max=array[i];
}
void arraymax::showv(){
	cout<<max<<endl;	
}
int main(){
	arraymax obj;
	int n;
	cin>>n;
	obj.setv(n);
	obj.maxv();
	obj.showv();
	return 0;
}

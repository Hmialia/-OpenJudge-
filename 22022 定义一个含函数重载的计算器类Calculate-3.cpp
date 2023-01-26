#include<iostream>
using namespace std;
class Calculate1{
public:
	float cheng(float a,float b){
		return a*b;
	}
	float chu(float a,float b){
		return a/b;
	}
	float jia(float a,float b){
		return a+b;
	}
	float jian(float a,float b){
		return a-b;
	}
	int cheng(int a,int b){
		return a*b;
	}
	int chu(int a,int b){
		return a/b;
	}
	int jia(int a,int b){
		return a+b;
	}
	int jian(int a,int b){
		return a-b;
	}
};
int main(){
	Calculate1 cal;
	int a,b;
	float c,d;
	cin>>c>>d;
	cin>>a>>b;
	cout<<cal.jia(c,d)<<endl;
	cout<<cal.jian(c,d)<<endl;
	cout<<cal.cheng(c,d)<<endl;
	cout<<cal.chu(c,d)<<endl;
	cout<<cal.jia(a,b)<<endl;
	cout<<cal.jian(a,b)<<endl;
	cout<<cal.cheng(a,b)<<endl;
	cout<<cal.chu(a,b)<<endl;
	return 0;
}

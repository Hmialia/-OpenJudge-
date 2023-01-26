#include<iostream>
using namespace std;
class fang{
private:
	float a,b;
public:
	float money(){
		return a*b*10;
	}
	fang(){}
	fang(int aa,int bb){
		a=aa;b=bb;	
	}	
};
class yuan{
private:
	float r;
public:
	float money(){
		return 3.14*r*r*10;	
	}
	yuan(){}
	yuan(float rr){
		r=rr;	
	}
};
int main(){
	float a,b,r1,r2;
	cin>>a>>b>>r1>>r2;
	fang o3(a,b);
	yuan o1(r1);
	yuan o2(r2);
	cout<<o1.money()+o2.money()+o3.money()<<endl;
	return 0;	
}

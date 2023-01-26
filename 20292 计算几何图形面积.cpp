#include<iostream>
using namespace std;

class ss{
private:
	int x;
	double a,b;
public:
	void Set(int an){
		x=2;
		a=an;
	}
	void Set(int an,int bn){
		x=1;
		a=an;
		b=bn;
	}
	double GetS(){
		if(x==2)return a*a*3.14159;
		else if(x==1)return a*b;
	}
};

int main(){
	int n;
	int x;
	double a,b;
	cin>>n;
	ss*ar=new ss[30];
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==2){
			cin>>a;
			ar[i].Set(a);
		}
		else if(x==1){
			cin>>a>>b;
			ar[i].Set(a,b);	
		}
	}
	for(int i=0;i<n;i++){
		cout<<ar[i].GetS()<<endl;
	}
	delete []ar;
	return 0;
}

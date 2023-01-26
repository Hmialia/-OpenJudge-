#include<iostream>
using namespace std;

class jiao{
	int ci;
	int n;
	
public:
	void jie();
	jiao(int);
	void displayCi(){
		cout<<ci<<endl;
	}
};

jiao::jiao(int nn){
	n=nn;
	ci=0;
}

void jiao::jie(){
	if(n==1)return;
	else if(n%2==0){
		n=n/2;
		ci++;
		jie();
		return;
	}
	else{
		n=n*3+1;
		ci++;
		jie();
		return;
	}
}

int main(){
	int n;
	cin>>n;
	jiao jiao2(n);
	jiao2.jie();
	jiao2.displayCi();
	return 0;	
}

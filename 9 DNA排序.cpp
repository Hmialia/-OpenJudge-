#include<iostream>
#include<string.h>
using namespace std;

class dna{
public:
	int n;
	int nx;
	char s[51];
	dna(){}
	void set(char ss[51],int nn){
		strcpy(s,ss);
		n=nn;
		nx=0;
		acc();
	}
	void acc(){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(s[i]>s[j])nx++;
			}
		}
	}
};

void swap(dna&a,dna&b){
	dna tem;
	tem.n=a.n;tem.nx=a.nx;strcpy(tem.s,a.s);
	a.n=b.n;a.nx=b.nx;strcpy(a.s,b.s);
	b.n=tem.n;b.nx=tem.nx;strcpy(b.s,tem.s);
}

int main(){
	int m,n;
	cin>>n>>m;
	dna dd[m];
	for(int i=0;i<m;i++){
		char s[n+1];
		cin>>s;
		dd[i].set(s,n);
	}
	for(int i=m-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(dd[j].nx>dd[j+1].nx){
				swap(dd[j],dd[j+1]);
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<dd[i].s<<endl;
	}	
	return 0;
}

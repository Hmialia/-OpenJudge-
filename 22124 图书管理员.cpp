#include<iostream>
using namespace std;
struct books{
	int number;
	bool exist=1;
};

int weishu(int a){
	int dg[8]={-1,9,99,999,9999,99999,999999,9999999};
	int x=1;
	for(int i=0;i<7;i++){
		x*=10;
		if(a>dg[i]&&a<=dg[i+1]){
			return x;
			break;
		}
	}
}

int main(){
	int n,q;
	cin>>n>>q;
	books book[n];
	int needer[q];
	for(int i=0;i<n;i++){
		cin>>book[i].number;
	}
	
	for(int i=0;i<q;i++){
		cin>>needer[i];
	}
	
	for(int i=0;i<q;i++){
		
		int ineed=0;
		int ineedn[n];
		for(int j=0;j<n;j++){
			if(book[j].exist&&(book[j].number-needer[i])%weishu(needer[i])==0){
				ineedn[ineed]=j;
				ineed+=1;
			}
		}
		
		if(ineed==0)cout<<"-1"<<endl;
		else if(ineed==1){
			cout<<book[ineedn[0]].number<<endl;
			book[ineedn[0]].exist=0;
		}
		else{
			int x=0;
			int min=book[ineedn[0]].number;
			for(int i=0;i<ineed;i++){
				if(book[ineedn[i]].number<min){
					min=book[ineedn[i]].number;
					x=i;
				}
			}
			cout<<book[ineedn[x]].number<<endl;
			book[ineedn[x]].exist=0;
		}
		
	}
}

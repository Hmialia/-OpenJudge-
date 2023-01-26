#include<iostream>
using namespace std;
struct players{
	int number;
	bool exist=1;
};
int main(){
	int n,m;
	cin>>n>>m;
	players player[n];
	for(int i=0;i<n;i++){
		player[i].number=i+1;
		cout<<i+1<<" ";
	}
	cout<<endl;
	int p=-1,member=0;
	int outer=0;
	while(1){
		do{
			if(p==n-1)p=0;
			else p++;
		}
		while(!player[p].exist);
		if(outer<n-1){
			member++;
			if(member==m){
				cout<<p+1<<" ";
				player[p].exist=0;
				member=0;
				outer++;
			}
		}
		else if(outer==n-1){
			cout<<endl<<"the winner is "<<p+1;
			break;
		}
	}    
	return 0;
}

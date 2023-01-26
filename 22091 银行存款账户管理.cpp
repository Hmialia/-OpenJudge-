#include<iostream>
#include<string.h>
using namespace std;
class Account{
private:
	int no;
	char name[10];
	float money;
public:
	Account(int,char*,float);
	void Deposit(float);
	void Withdraw(float);
	void Show();
};
Account::Account(int n,char*p,float m){
	no=n;
	strcpy(name,p);
	money=m;
}
void Account::Show(){
	cout<<money<<endl;	
}
void Account::Deposit(float add){
	money+=add;
	Show();
}
void Account::Withdraw(float red){
	if(red<=money){
		money-=red;
	}
	Show();		
}
int main(){
	int n;
	char p[10];
	float m;
	cin>>n>>p>>m;
	Account obj(n,p,m);
	int a;
	cin>>a;
	switch(a){
		case 1:{
			float add;
			cin>>add;
			cout<<n<<":";
			obj.Deposit(add);
			break;
		}
		case 2:{
			float red;
			cin>>red;
			cout<<n<<":";
			obj.Withdraw(red);
			break;
		}	
		case 3:{
			cout<<n<<":";
			obj.Show();
			break;
		}
		case 0:break;
	}
	return 0;	
}

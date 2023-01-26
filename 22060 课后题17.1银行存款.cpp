#include<iostream>
using namespace std;

class Account{
public:
	Account(){balance=0;}
	Account(unsigned acntNo,float balan=0);//ÒÔÕËºÅºÍ½áËãÓà¶î¹¹Ôì
	unsigned AccountNo(){return acntNumber;}//²éÑ¯ÕËºÅ 
	float AcntBalan(){return balance;}//²éÑ¯Óà¶î 
	void Display()const;//ÏÔÊ¾ÕËºÅºÍÓà¶î
	void Deposit(float amount);//´æ¿î
	virtual void Withdrawal(float amount){return;}//(Ðéº¯Êý)È¡¿î
	
protected:
	unsigned acntNumber;//ÕËºÅ
	float balance;//Óà¶î 
};

Account::Account(unsigned acntNo,float balan):acntNumber(acntNo),balance(balan){}  

void Account::Display()const{
	cout<<acntNumber<<" "<<balance<<endl;
}

void Account::Deposit(float amount){
	balance+=amount;
	cout<<acntNumber<<" "<<amount<<endl;
}


//-------------------------------------------------------------

class Savings:public Account{
public:
	Savings(unsigned acntNo,float balan=0.0);
	virtual void Withdrawal(float amount);
protected:
	static float minbalance;//Í¸Ö§·¶Î§£» 
};

float Savings::minbalance=500;//ÉèÖÃ×î¶àÍ¸Ö§500Ôª£»

Savings::Savings(unsigned acntNo,float balan):Account(acntNo,balan){}

void Savings::Withdrawal(float amount){
	float actualWithd;
	if(balance+minbalance<amount)
		actualWithd=0;
	else
		actualWithd=amount;
	balance-=actualWithd;
	cout<<acntNumber<<" "<<actualWithd<<endl;
}

//------------------------------------------------------------

enum REMIT{remitByPost,remitByCable,other};//£¨Ã¶¾ÙÐÍ£©È¡Ç®ÀàÐÍ{ÐÅ»ã£¬µç»ã£¬³£¹æ}
class Checking:public Account{
protected:
	REMIT remittance;
public:
	Checking(unsigned acentNo,float balan=0.0);
	void Withdrawal(float amount);
	void setRemit(REMIT re){remittance=re;}
};

Checking::Checking(unsigned acntNo,float balan):Account(acntNo,balan),remittance(other){}

void Checking::Withdrawal(float amount){
	float actualWithd;
	if(remittance==remitByPost) actualWithd=amount+30;
	else if(remittance==remitByCable) actualWithd=amount+60;
	else actualWithd=amount;
	if(actualWithd>amount) actualWithd=0;
	balance-=actualWithd;
	cout<<acntNumber<<" "<<actualWithd<<endl;
}

//-----------------------------------------------------------

int main(){
	int n;
	cin>>n;
	Account* acc[n] = {NULL};
	char unt;
	unsigned number;
	float deposit;
	for(int i=0;i<n;i++){
		cin>>unt>>number>>deposit;
		if(unt=='S')acc[i]=(Account*) new Savings(number,deposit);
		else acc[i]=(Account*) new Checking(number,deposit);
	}
	for(int i=0;i<n;i++){
		acc[i]->Display();
	}
	for (int i = 0; i<n; i++)
	{
		if (acc[i] != NULL)  delete acc[i];
	}
	return 0;
}

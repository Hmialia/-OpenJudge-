#include<iostream>
using namespace std;
class Fruit
{
public:
	Fruit()
	{
		cout<<"Fruit default constructor called."<<endl;
	}
	Fruit(char* pz,char* cd)
	{
		PinZhong=pz;
		ChanDi=cd;
		cout<<"Fruit constructor called."<<endl;
	}
	void print()
	{
		cout<<PinZhong<<" "<<ChanDi<<endl;
	}
	virtual ~Fruit()
	{
		cout<<"Fruit distructor called."<<endl;
	}
protected:
	char* PinZhong;
	char* ChanDi;
};

class Apple:public Fruit
//补充代码
{
private:
	float m,price;
public:
	Apple(){
		cout<<"Apple default constructor called."<<endl;
	}
	Apple(char* pz,char* cd,float mm,float p):Fruit(pz,cd){
		m=mm;
		price=p;
		cout<<"Apple constructor called."<<endl;
	}
	virtual ~Apple()
	{
		cout<<"Apple distructor called."<<endl;
	}
	void print(){
		cout<<PinZhong<<" "<<ChanDi<<endl;
		cout<<"Totle price:"<<m*price<<endl;
	}
	
};
int main()
{
	Apple ap[2];
	ap[0]=Apple("FuShi","ShanDong",5.5,7.8);
	ap[1]=Apple("GuoGuang","ShanXi",4.8,9.5);
	for(int i=0;i<2;i++)
		ap[i].print();
	return 0;
}

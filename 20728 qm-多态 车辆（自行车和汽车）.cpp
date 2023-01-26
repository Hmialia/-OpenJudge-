using namespace std;
#include<iostream>

class Vehicle{
protected:
	int maxSpeed;
	int weight;
public:
	Vehicle(){}
	Vehicle(int a,int b){
		maxSpeed=a;weight=b;
	}
	virtual ~Vehicle(){}
	virtual void print()=0;
};

class Bicycle:public Vehicle{
protected:
	int height;
public:
	Bicycle(){}
	Bicycle(int a,int b,int c):Vehicle(a,b){
		height=c;
	}
	virtual ~Bicycle(){}
	virtual void print(){
		cout<<"maxSpeed is "<<maxSpeed<<",weight is "<<weight<<",height is "<<height<<endl;
	}
};

class Motocar:public Vehicle{
protected:
	int seatNum;
public:
	Motocar(){}
	Motocar(int a,int b,int c):Vehicle(a,b){
		seatNum=c;
	}
	virtual ~Motocar(){}
	virtual void print(){
		cout<<"maxSpeed is "<<maxSpeed<<",weight is "<<weight<<",seatNum is "<<seatNum<<endl;
	}
};


int main()
{
	int const N=2;
	double maxSpeed(0),weight(0),height(0),seatNum(0);
	Vehicle *pvehicle[N];	
	for(int i=0;i<N;i++)
	{
		pvehicle[i]=NULL;
	}
	
	maxSpeed=3;
	weight=4;
	
	height=1;
	pvehicle[0]=new Bicycle(maxSpeed,weight,height);
	
	seatNum=2;
	pvehicle[1]=new Motocar(maxSpeed,weight,seatNum);
	
	for(int i=0;i<N;i++)
	{
		if(pvehicle[i]!=NULL)
		{
			pvehicle[i]->print();
			delete pvehicle[i];
		}			
	}	
	
	return 0;
}

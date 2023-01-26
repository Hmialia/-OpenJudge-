#include<iostream>
using namespace std;

class Transport{
public:
	void start(){
		cout<<"Start Transport"<<endl;
	}
	void stop(){
		cout<<"Stop Transport"<<endl;
	}
	Transport(){
		cout<<"Construct Transport"<<endl;
	}
};

class Vehicle:public Transport{
public:
	void start(){
		cout<<"Start Vehicle"<<endl;
	}
	void stop(){
		cout<<"Stop Vehicle"<<endl;
	}
	Vehicle(){
		cout<<"Construct Vehicle"<<endl;
	}
};

class Car:public Vehicle{
public:
	void start(){
		cout<<"Start Car"<<endl;
	}
	void stop(){
		cout<<"Stop Car"<<endl;
	}
	Car(){
		cout<<"Construct Car"<<endl;
	}
};

class Bus:public Vehicle{
public:
	void start(){
		cout<<"Start Bus"<<endl;
	}
	void stop(){
		cout<<"Stop Bus"<<endl;
	}
	Bus(){
		cout<<"Construct Bus"<<endl;
	}
};

class HongQi:public Car{
public:
	void start(){
		cout<<"Start HongQi"<<endl;
	}
	void stop(){
		cout<<"Stop HongQi"<<endl;
	}
	HongQi(){
		cout<<"Construct HongQi"<<endl;
	}
};

int main(){
	Bus b;
	b.start();
	b.stop();
	HongQi a;
	a.start();
	a.stop();
}


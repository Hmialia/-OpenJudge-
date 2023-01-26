#include<iostream>
using namespace std;

class Car{
private:
	int size;
public:
	Car(int j){
		size=j;
	}
	int Get(){
		return size;
	}
};

class Boat{
private:
	int size;
public:
	Boat(int j){
		size=j;
	}
	int Get(){
		return size;
	}
};

int Leisure(int time, Car& aobj, Boat& bobj){
	return time * aobj.Get() * bobj.Get();
}

int main(){
	Car c1(2);
	Boat b1(3);
	int time =4;
	cout <<Leisure(time,c1,b1);
}

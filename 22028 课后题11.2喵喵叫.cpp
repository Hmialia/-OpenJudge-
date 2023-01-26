#include<iostream>
using namespace std;
class cat{
private:
	int age;
public:
	void SetAge(int a){
		age=a;
	}
	int GetAge(){
		return age;
	}
	void Meow(){
		cout<<"Meow.\n";
	}
};
int main(){
	cat frisky;
	frisky.SetAge(5);
	frisky.Meow();
	cout<<"frisky is a cat who is "<<frisky.GetAge()<<" years old."<<endl;
	frisky.Meow();
	return 0;
}

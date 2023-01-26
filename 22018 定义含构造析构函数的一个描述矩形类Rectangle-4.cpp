#include<iostream>
using namespace std;
class Rectangle4{
private:
	double width,length;
public:
	void Show();
	double GetWidth();
	double GetLength();
	Rectangle4(){
		width=0;length=0;
	}
	Rectangle4(double a,double b){
		width=a;length=b;
	}
	Rectangle4(Rectangle4 & a){
		width=a.GetWidth();length=a.GetLength();
	}
	~Rectangle4(){
		cout<<"Destruction"<<length<<","<<width<<endl;
	}
};
double Rectangle4::GetLength(){
	return length;
}
double Rectangle4::GetWidth(){
	return width;
}
void Rectangle4::Show(){
	cout<<length<<endl
	<<width<<endl
	<<(width+length)*2<<endl
	<<width*length<<endl;
}


int main(){
	Rectangle4 rec1;
	rec1.Show();
	Rectangle4 rec2(1.1,2.2);
	rec2.Show();
	Rectangle4 rec3(rec2);
	rec3.Show();
}

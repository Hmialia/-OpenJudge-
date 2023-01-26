#include<iostream>
using namespace std;
class Rectangle1{
public:
	int width,length;
	int GetCalcircle(){
		return (width+length)*2;
	}
	int GetCalarea(){
		return width*length;
	}
};
int main(){
	int w,l;
	cin>>w>>l;
	Rectangle1 rec;
	rec.width=w;rec.length=l;
	cout<<rec.width<<endl
	<<rec.length<<endl
	<<rec.GetCalcircle()<<endl
	<<rec.GetCalarea();
}

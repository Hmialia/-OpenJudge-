#include<iostream>
using namespace std;
class Rectangle3{
private:
	int width,length;
public:
	void calcircle(int,int);
	void calarea(int,int);
};
void Rectangle3::calcircle(int w,int l){
	width=w;length=l;
	cout<<width<<endl
	<<length<<endl
	<<(width+length)*2<<endl;
}
void Rectangle3::calarea(int w,int l){
	width=w;length=l;
	cout<<width<<endl
	<<length<<endl
	<<width*length<<endl;
}
int main(){
	int w,l;
	cin>>w>>l;
	Rectangle3 rec;
	rec.calcircle(w,l);
	rec.calarea(w,l);
	return 0;
}

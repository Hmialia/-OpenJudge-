#include<iostream>
using namespace std;
class Rectangle2{
private:
	int width,length;
public:
	void SetWidth(int);
	void SetLength(int);
	void ShowWidth();
	void ShowLength();
	void ShowCalcircle();
	void ShowCalarea();
};
void Rectangle2::SetLength(int l){
	length=l;
}
void Rectangle2::SetWidth(int w){
	width=w;
}
void Rectangle2::ShowLength(){
	cout<<length<<endl;
}
void Rectangle2::ShowWidth(){
	cout<<width<<endl;
}
void Rectangle2::ShowCalcircle(){
	cout<<(length+width)*2<<endl;
}
void Rectangle2::ShowCalarea(){
	cout<<length*width<<endl;
}
int main(){
	int w,l;
	cin>>w>>l;
	Rectangle2 rec;
	rec.SetWidth(w);rec.SetLength(l);
	rec.ShowWidth();
	rec.ShowLength();
	rec.ShowCalcircle();
	rec.ShowCalarea();
	return 0;
}

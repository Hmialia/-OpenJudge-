#include <iostream>
using namespace std;
class Point
{
private:
	int x,y;
public:
	void print(){
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
	Point(){
		x=y=0;
		print();
	}
	Point(int xx,int yy=5){
		x=xx;
		y=yy;
		print();
	}
	Point(const Point& a){
		x=a.x;
		y=a.y;
		cout<<"copy constrator called!"<<endl;
	}
	void add(const Point& a){
		x+=a.x;
		y+=a.y;
		print();
	}
};
int main()
{
	Point a;
	Point b(3);
	Point c(2,4);
	Point d(c);
	d.add(b);
	return 0;
}

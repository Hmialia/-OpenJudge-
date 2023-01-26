#include <iostream>
#include <math.h>
using namespace std;
class Point
{
public:
	Point(double x,double y)
	{
		X = x;
		Y = y; 
	}
	Point(const Point& p)
	{
		X = p.X;
		Y = p.Y;
	}
	void setXY(double x,double y)
	{
		X = x;
		Y = y;
	}
	double getX()
	{
		return X;
	}
	double getY()
	{
		return Y;
	}
private:
	double X,Y;
};
class Line
{
private:
	Point p1;Point p2;
public:
	Line(double x1,double y1,double x2,double y2):p1(x1,y1),p2(x2,y2){
	}
	double getLength(){
		return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
	}	
};
int main()
{
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Line ln(x1,y1,x2,y2);
	cout<<ln.getLength()<<endl;	
	return 0;
}

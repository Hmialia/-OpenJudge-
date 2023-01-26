#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Point{
private:
	double x,y;
public:
	Point(double a,double b){
		x=a; y=b;
	}
	double GetAngle(){
		return atan(y/x)*(180/3.14159265359);
	}
	double GetRadius(){
		return sqrt(x*x+y*y);
	}
	double GetX(){
		return x;
	}
	double GetY(){
		return y;
	}
};
int main(){
	double x,y;
	cin>>x>>y;
	Point poi(x,y);
	cout<<"angle="<<fixed<<setprecision(3)<<poi.GetAngle()<<","
	<<"radius="<<fixed<<setprecision(5)<<poi.GetRadius()<<","
	<<"x offset="<<fixed<<setprecision(0)<<poi.GetX()<<","
	<<"y offset="<<fixed<<setprecision(0)<<poi.GetY()<<endl;
	return 0;
}

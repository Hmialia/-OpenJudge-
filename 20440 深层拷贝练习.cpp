#include <iostream>
using namespace std;
#include<iostream>
using namespace std;
class Point{
private:
	int x,y;
public:
	Point(){
		x=0;y=0;	
	}
	Point(int a,int b){
		x=a;y=b;	
	}
	Point(Point& a){
		x=a.x;y=a.y;
	}
	~Point(){};
	void move(int a,int b){
		x=a;y=b;	
	}
	int getX(){
		return x;	
	}
	int getY(){
		return y;	
	}
	void setX(int a){
		x=a;	
	}
	void setY(int a){
		y=a;	
	}
};
class AofPoint{
private:
	Point*p=new Point[100];
	int n;
public:
	AofPoint(int x){
		n=x;	
	}
	~AofPoint(){};
	AofPoint(AofPoint& a){
		for(int i=0;i<a.n;i++){
			p[i]=a.p[i];	
		}
		n=a.n;
	}
	Point& visit_point(int a){
		return p[a];	
	}
};
int main()
{
	AofPoint afp(3);//创建afp对象时，也设置了动态对象数组的大小
	
	afp.visit_point(1).move(4,6);
	afp.visit_point(2).move(8,16);
	//	cout << "输出第一个对象数组内容" << endl;
	cout << "point(1):x=" << afp.visit_point(1).getX()  << ",y=" << afp.visit_point(1).getY() << endl;
	cout << "point(2):x=" << afp.visit_point(2).getX() << ",y=" << afp.visit_point(2).getY() << endl;
	
	AofPoint afp2(afp);
	//	cout << "输出第二个对象数组内容" << endl;
	cout << "point(1):x=" << afp2.visit_point(1).getX() << ",y=" << afp2.visit_point(1).getY() << endl;
	cout << "point(2):x=" << afp2.visit_point(2).getX()  << ",y=" << afp2.visit_point(2).getY() << endl;
	//	cout << "改变第一个对象数组的内容,看看是否影响第二个对象数组" << endl;
	cout<<"Change:\n";	
	afp.visit_point(1).move(8, 8);
	afp.visit_point(2).move(9, 9);
	//	cout << "输出第一个对象数组的内容" << endl;
	
	cout << "point(1):x=" << afp.visit_point(1).getX() << ",y=" << afp.visit_point(1).getY() << endl;
	cout << "point(2):x=" << afp.visit_point(2).getX() << ",y=" << afp.visit_point(2).getY() << endl;
	//	cout << "输出第二个对象数组内容" << endl;
	cout << "point(1):x=" << afp2.visit_point(1).getX() << ",y=" << afp2.visit_point(1).getY() << endl;
	cout << "point(2):x=" << afp2.visit_point(2).getX()  << ",y=" << afp2.visit_point(2).getY() << endl;
	//	cout << "若第二个对象数组内容还是原来的，说明达到了深层复制的目的" << endl;
	
	return 0;
}

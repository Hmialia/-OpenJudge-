#include<iostream>
using namespace std;
class Rectangle{
private:
	float width,length,area;
public:
	Rectangle(float x,float y)
	{
		width = x;
		length = y;
		area = x*y;
	}
	friend float operator + (Rectangle&,Rectangle&);
	friend float operator - (Rectangle&,Rectangle&);
	
	
};
float operator + (Rectangle& a,Rectangle& b){
	float add; 
	add=a.area+b.area;
	return add;
}
float operator - (Rectangle& a,Rectangle& b){
	float bdd;
	bdd=a.area-b.area;
	return bdd;
}
int main()
{
	float x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Rectangle r1(x1,y1),r2(x2,y2);
	cout<<r1+r2<<" "<<r1-r2<<endl;
	return 0;
}

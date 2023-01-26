#include <iostream> 
using namespace std;

class Box
{
	double width;
	double height;
	double depth;
public:
	friend void printArea(Box);
	void inputBox(){
		cin>>width>>height>>depth;
	}
	void printInfo(){
		cout<<"The size of box:("
		<<width<<","<<height<<","<<depth<<")";
	}
	
	
	
};
void printArea(Box box)
{
	cout<<box.width*box.height*box.depth;
}

// 程序的主函数
int main( )
{
	
	Box box;
	box.inputBox(); 
	box.printInfo();
	cout<<'\n'; 
	printArea( box );// 输出体积
	
	return 0;
}

#include<iostream>
using namespace std;
class fang{
private:
	float l,w,h,v;
public:
	void setl(float ll){l=ll;}
	void setw(float ww){w=ww;}
	void seth(float hh){h=hh;}
	void calv(){v=l*w*h;}
	float getv(){return v;}
};
int main(){
	fang obj;
	float a,b,c;
	cin>>a>>b>>c;
	obj.setl(a);
	obj.setw(b);
	obj.seth(c);
	obj.calv();
	cout<<obj.getv()<<endl;
	return 0;
}

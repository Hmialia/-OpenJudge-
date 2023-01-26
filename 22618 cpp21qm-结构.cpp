#include<iostream>
using namespace std;

struct point{
	int x;
	int y;
	int distance;
};

int main(){
	int n;
	cin>>n;
	point a[10];
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[i].x=x;a[i].y=y;
		a[i].distance=x*x+y*y;
	}
	for(int j=1;j<n;j++){
		int f=1;
		for(int i=0;i<n-1;i++)
			if(a[i].distance>a[i+1].distance){
			point t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			f=0;
		}
		if(f)break;
	}
	
	for(int i=0;i<n;i++){
		cout<<"("<<a[i].x<<","<<a[i].y<<") ";
	}
	
	return 0;
}

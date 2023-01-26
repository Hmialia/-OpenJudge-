#include <iostream>
using namespace std;

void display(int count,int index)
{
	if(count>0)
		cout<<count<<","<<index<<endl;
	else
		cout<<"none"<<endl;
}
int findcount(int* p,int n,int x,int& index){
	int ct=0;
	bool flag=1;
	for(int i=0;i<n;i++){
		if(p[i]==x){
			ct++;
			if(flag){
				index=i+1;
				flag=0;
			}
		}
	}
	return ct;
}
int main()
{
	int a[10] = { 5, 7, 8, 9, 8, 2, 7, 3, 6, 4 };
	int b[7] = { 5, 2, 5, 6, 5, 7, 9};
	int ct,index;
	ct = findcount(a, 10, 8,index);
	display(ct,index);
	ct = findcount(b, 7, 5,index);
	display(ct,index);
	ct = findcount(b, 7, 1,index);
	display(ct,index);	
	return 0;
}

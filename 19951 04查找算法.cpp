#include<iostream>
using namespace std;
#define MAXSIZE 100
int BinFind(int a[],int n)			
{
	for(int i=0;i<n;i++){
		if(a[i]==i){
			return i;
		}
	}
	
	return -1;
}

void display(int a[],int n)			//输出测试结果
{
	
	int i=BinFind(a,n);
	if (i != -1)
		cout << i;
	else
		cout << "no answer";
}
int main()
{
	int nCout = 0;
	cin >> nCout;
	int cca[MAXSIZE];
	for (int i = 0; i < nCout; i++)
		cin >> cca[i];
	display(cca, nCout);
	system("pause");
	return 0;
	
}

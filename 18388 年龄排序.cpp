#include<iostream>
using namespace std;
struct students{
	char name[20];
	char sex[10];
	int byea;
	int bmon;
};
void maopao(students*xiaom,int l){
	for(int i=1;i<l;i++)
		for(int j=0;j<l-i;j++)
			if(xiaom[j].byea+(double)xiaom[j].bmon/12<xiaom[j+1].byea+(double)xiaom[j+1].bmon/12){
		students temp=xiaom[j];
		xiaom[j]=xiaom[j+1];
		xiaom[j+1]=temp;
	}
	
}
int main(){
	int n;
	cin>>n;
	students student[n];
	for(int i=0;i<n;i++){
		cin>>student[i].name>>student[i].sex>>student[i].byea>>student[i].bmon;
	}
	maopao(student,n);
	for(int i=0;i<n;i++){
		cout<<student[i].name<<" "<<student[i].sex<<" "<<student[i].byea<<" "<<student[i].bmon<<endl;
	}
}

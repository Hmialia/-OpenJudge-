#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;
struct students{
	char name[20];
	int month,day,birthcode;
	bool exist=1;
};
bool cmp(const students &a,const students &b){
	if(a.birthcode!=b.birthcode)return a.birthcode<b.birthcode;
	else{
		if(strlen(a.name)!=strlen(b.name))return strlen(a.name)<strlen(b.name);
		else return strcmp(a.name,b.name)<0;
	}
}
int main(){
	int n;
	cin>>n;
	students student[n];
	for(int i=0;i<n;i++){
		cin>>student[i].name>>student[i].month>>student[i].day;
		student[i].birthcode=student[i].month*40+student[i].day;
	}
	sort(student,student+n,cmp);
	//	cout<<endl;
	//	for(int i=0;i<n;i++)cout<<student[i].name<<" "<<student[i].month<<" "<<student[i].day<<" "<<student[i].birthcode<<endl;
	int p=0;
	while(p<n-1&&student[p].birthcode!=student[p+1].birthcode)p++;
	if(p==n-1)cout<<"None";
	else 
		do{
		cout<<student[p].month<<" "<<student[p].day<<" "<<student[p].name<<" ";
		p++;
		while(p<n-1&&student[p].birthcode==student[p+1].birthcode){
			cout<<student[p].name<<" ";
			p++;
		}
		cout<<student[p].name<<endl;
		if(p<n-1)p++;
		else break;
		while(p<n-1&&student[p].birthcode!=student[p+1].birthcode)p++;
		if(p==n-1)break;
	}
	while(p<n);
	return 0;
}

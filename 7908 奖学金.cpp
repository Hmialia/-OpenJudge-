#include<iostream>
#include<algorithm>
using namespace std;
struct students{
	int chinese,math,english,score,serial;
};
bool cmp(const students &a,const students &b){
	if(a.score!=b.score)return a.score>b.score;
	else{
		if(a.chinese!=b.chinese)return a.chinese>b.chinese;
		else return a.serial<b.serial;
	}
}
int main(){
	int n;
	cin>>n;
	students student[n];
	for(int i=0;i<n;i++){
		cin>>student[i].chinese>>student[i].math>>student[i].english;
		student[i].score=student[i].chinese+student[i].math+student[i].english;
		student[i].serial=i+1;
	}
	sort(student,student+n,cmp);
	for(int i=0;i<5;i++)cout<<student[i].serial<<" "<<student[i].score<<endl;
	return 0;
}

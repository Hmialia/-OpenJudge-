#include<iostream>
#include<algorithm>
using namespace std;
struct applicants{
	int serial,score;
};

bool cmp(const applicants &A,const applicants &B){
	return (A.score>B.score)||(A.score==B.score&&A.serial<B.serial);
}
int main(){
	int m,n;
	cin>>n>>m;
	m=m+m/2;
	applicants applicant[n];
	for(int i=0;i<n;i++)cin>>applicant[i].serial>>applicant[i].score;
	sort(applicant,applicant+n,cmp);
	while(applicant[m].score==applicant[m-1].score)m++;
	cout<<applicant[m-1].score<<" "<<m<<endl;
	for(int i=0;i<m;i++)cout<<applicant[i].serial<<" "<<applicant[i].score<<endl;
	return 0;
}

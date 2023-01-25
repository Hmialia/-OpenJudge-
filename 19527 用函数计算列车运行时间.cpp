#include <iostream>
using namespace std;
int hms_To_second(int h,int m,int s)
{
	return h*3600+m*60+s;
}
int main()
{
	int H1,M1,S1,H2,M2,S2;
	cin>>H1>>M1>>S1;
	cin>>H2>>M2>>S2;
	cout<<hms_To_second(H2,M2,S2)-hms_To_second(H1,M1,S1);
	return 0;
}

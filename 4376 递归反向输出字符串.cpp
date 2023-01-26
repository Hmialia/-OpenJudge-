#include<iostream>
using namespace std;

//¸ù¾ÝÌâÄ¿ÒÔ'E'Îª½áÊøÊäÈë±êÖ¾·û
void fun(){
	char a;
	cin>>a;
	if(a=='E'){
		cout<<a;
		return;
	}
	else{
		fun();
		cout<<a;
		return;
	}
}


int main(){
	fun();
	return 0;
}

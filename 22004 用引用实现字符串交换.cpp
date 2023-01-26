#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

void swap(string&a,string&b){
	string t=a;
	a=b;
	b=t;	
}

int main(){
	char * ap="hello";
	char * bp="how are you?";
	cout<<ap<<endl<<bp<<endl<<"change";
	swap(ap,bp);
	cout<<endl<<ap<<endl<<bp;
	return 0;
}

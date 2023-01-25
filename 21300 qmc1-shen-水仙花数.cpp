#include <iostream>
using namespace std;

int main()
{
	int hun, ten, ind, n;
	//补充代码
	for(hun=1;hun<=9;hun++){
		for(ten=0;ten<=9;ten++){
			for(ind=0;ind<=9;ind++){
				n=hun*hun*hun+ten*ten*ten+ind*ind*ind;
				if(hun*100+ten*10+ind==n){
					cout<<hun<<ten<<ind<<endl;
				}
			}
		}
	}
	return 0;
}

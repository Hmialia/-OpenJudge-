#include<iostream>
#include<cstring>

using namespace std;
#define MaxSize 102

int main(){
	int map[MaxSize][MaxSize];
	memset(map,-1,sizeof(map));
	int n,m;cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a,b,l;cin>>a>>b>>l;
		map[a-1][b-1]=map[b-1][a-1]=l;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

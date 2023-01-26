#include<iostream>
using namespace std;

void acc(int*alpha,char*s){
	for(int i=0;i<80;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			alpha[s[i]-'A']++;
		}
		else if(s[i]=='\0'){
			break;
		}
	}
}

void print(int*alpha,int n){
	int max=alpha[0];
	for(int i=0;i<n;i++){
		if(alpha[i]>max)max=alpha[i];
	}
	for(;max>0;max--){
		for(int j=0;j<n;j++){
			if(alpha[j]==max){
				cout<<"* ";
				alpha[j]--;
			}
			else cout<<"  ";
		}
		cout<<endl;
	}
}

int main(){
	char s[4][80];
	for(int i=0;i<4;i++)cin.getline(s[i],80);
	int alpha[26]={0};
	for(int i=0;i<4;i++)acc(alpha,s[i]);
	print(alpha,26);
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
}

#include<iostream>
using namespace std;
char change(char ch);

int main(){
	char msg[] = "I love C++ programming!";
	int i = 0;
	while (msg[i] != '\0'){
		cout << change(msg[i]);
		i++;
	}
	return 0;
}

char change(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return 'a' + 'a' + 25 - ch;
	else if (ch >= 'A' && ch <= 'Z')
		return 'A' + 'A' + 25 - ch;
	else return ch;
}

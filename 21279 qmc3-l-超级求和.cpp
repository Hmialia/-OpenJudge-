#include<iostream>
using namespace std;
int sumFun(int n);
int main() {
	int n;
	cin >> n;
	cout << sumFun(n);
	return 0;
}

int sumFun(int n) {
	long int tempsum = 0;
	if (n == 1)return 1;
	else return sumFun(n - 1) + (1 + n) * n / 2;
}

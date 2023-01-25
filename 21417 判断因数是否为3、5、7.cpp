#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	bool flag = 1;
	for (int i = 3; i < 9; i += 2) {
		if (n % i == 0) {
			cout << i << " ";
			flag = 0;
		}
	}
	if (flag)cout << "n";
	return 0;
}

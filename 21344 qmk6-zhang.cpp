#include<iostream>
using namespace std;
int main() {
	int y[20],n[20];
	cin >> n[0];
	int k = 0;
	for (int i = 1; i < 20; i++) {
		cin >> y[i];
		bool flag = 1;
		for (int j = 0; j < i; j++) {
			if (y[i] == n[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			k++;
			n[k] = y[i];
		}
	}
	for (int l = 0; l <= k; l++) {
		cout << n[l] << " ";
	}
	return 0;
}

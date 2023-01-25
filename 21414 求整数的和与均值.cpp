#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* p = new int[n];
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		sum += p[i];
	}
	cout << sum << " " << fixed << setprecision(5) << sum / n << endl;
	return 0;
}

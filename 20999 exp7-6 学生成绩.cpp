#include<iostream>
using namespace std;

void h(int r,int c,int a[][50]){
	int z[10000];
	for(int i=0;i<r;i++){
		z[i]=0;
		for(int j=0;j<c;j++)z[i]=z[i]+a[i][j];
	}
	int m=z[0],b=1;
	for(int k=1;k<r;k++){
		if(z[k]>m){
			m=z[k];
			b=k+1;
		}
	}
	cout<<b<<" ";
	for(int l=0;l<c;l++){
		cout<<a[b-1][l]<<" ";
	}
	cout<<endl;
}

void uc(int r, int c, int a[][50]) {
	for (int m=0;m<r;m++) {
		for (int n = 0; n < c; n++) {
			if (a[m][n] < 60) {
				cout << m + 1 << " ";
				for (int o = 0; o < c; o++)cout << a[m][o] << " ";
				cout << endl;
				break;
			}
		}
	}
}

double p(int r, int c, int a[][50]) {
	double d=0;
	for (int p = 0; p < r; p++) {
		for (int q = 0; q < c; q++)
			d = d + a[p][q];
	}
	return d / (r * c);
}

int main(){
	int n=5,m=4;
	int a[][50]={{88,67,48,91},{61,65,37,77},{92,81,73,60},{51,55,60,60},{77,63,70,80}};
	h(n,m,a);
	uc(n,m,a);
	cout<<p(n,m,a);
	return 0;
} 

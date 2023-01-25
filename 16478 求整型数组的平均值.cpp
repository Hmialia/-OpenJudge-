#include <stdio.h>

//函数返回数组所有元素的平均值。​
double average(int *buf, int size);

int main(void)
{
	int a[8] = {49, 38, 65, 97, 76, 13, 27, 49};
	int b[10] = {3, 7, 2, 9, 5, 9, 12, 31, 99, 79};
	printf("%.3lf\n", average(a, 8));
	printf("%.3lf\n", average(b, 10));
	return 0;
}
double average(int a[],int n){
	double s=0;
	for(int i=0;i<n;i++)s=s+a[i];
	return s/n;
}

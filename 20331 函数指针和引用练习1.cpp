#include<iostream>
using namespace std;

void exchange_value(int, int);  //值作参数，函数参数值
void exchange_pointer1(int*, int*);  //指针作参数1，交换指针指向内容
void exchange_pointer2(int*, int*);  //指针作参数2，交换指针
void exchange_reference(int&, int&);  //引用作参数，交换参数值
void exchange(int, int);  //值作参数，函数参数值
void exchange(int*, int*);  //指针作参数1，交换指针指向内容
void exchange(int*, int*, int);  //指针作参数2，交换指针 。第三个传实参0。

int main() {
	int a = 1, b = 2;
	exchange_value(a, b);
	cout << "a=" << a << "," << "b=" << b << endl;
	
	a = 1, b = 2;
	exchange_pointer1(&a, &b);
	cout << "a=" << a << "," << "b=" << b << endl;
	
	a = 1, b = 2;
	exchange_pointer2(&a, &b);
	cout << "a=" << a << "," << "b=" << b << endl;
	
	a = 1, b = 2;
	exchange_reference(a, b);
	cout << "a=" << a << "," << "b=" << b << endl;
	
	a = 1, b = 2;
	exchange(a, b);
	cout << "a=" << a << "," << "b=" << b << endl;
	
	a = 1, b = 2;
	exchange(&a, &b);
	cout << "a=" << a << "," << "b=" << b << endl;
	
	a = 1, b = 2;
	exchange(&a, &b,0);
	cout << "a=" << a << "," << "b=" << b << endl;
}

void exchange_value(int a, int b){
	int t = a;
	a = b;
	b = t;
}

void exchange_pointer1(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void exchange_pointer2(int* a, int* b){
	int *t = a;
	a = b;
	b = t;
}

void exchange_reference(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

void exchange(int a, int b){
	int t = a;
	a = b;
	b = t;
}

void exchange(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void exchange(int* a, int* b, int c=0){
	int* t = a;
	a = b;
	b = t;
}

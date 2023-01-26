#include <iostream>
using namespace std;

#define MAX_SIZE 100

typedef int KeyType;
typedef int ElemType;
typedef struct {	
	KeyType key;
	ElemType data;
} SqType;

// 补充以下快速排序函数代码，使得输入参数desc为0时实现升序，desc为1时实现降序
void QuickSort(SqType R[], int s, int t, int desc)
{
	int i = t, j = s;
	SqType tmp;
	if (s < t) {
		if(!desc){
			tmp=R[s];      //ÓÃÇø¼äµÄµÚ1¸öÔªËØ×÷Îª»ù×¼
			while (i!=j){     //´ÓÇø¼äÁ½¶Ë½»ÌæÏòÖÐ¼äÉ¨Ãè£¬Ö±ÖÁi=jÎªÖ¹
				while (j<i&& R[i].key>=tmp.key)
					i-- ; //´ÓÓÒÏò×óÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×ÖÐ¡ÓÚtmp. keyµÄR[j]
				R[j] =R[i]; //½«RCflÇ°ÒÆµ½R[i]µÄÎ»ÖÃ
				while (i>j && R[j].key<=tmp.key)
					j++; //´Ó×óÏòÓÒÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×Ö´óÓÚtmp. keyµÄÔªËØR[i]
				R[i]=R[j]; //½«R[i]ºóÒÆµ½R&]µÄÎ»ÖÃ
			}
			R[j] = tmp; 	//TODO
		}
		else{
			tmp=R[s];      //ÓÃÇø¼äµÄµÚ1¸öÔªËØ×÷Îª»ù×¼
			while (i!=j){     //´ÓÇø¼äÁ½¶Ë½»ÌæÏòÖÐ¼äÉ¨Ãè£¬Ö±ÖÁi=jÎªÖ¹
				while (j<i&& R[i].key<=tmp.key)
					i-- ; //´ÓÓÒÏò×óÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×ÖÐ¡ÓÚtmp. keyµÄR[j]
				R[j] =R[i]; //½«RCflÇ°ÒÆµ½R[i]µÄÎ»ÖÃ
				while (i>j && R[j].key>=tmp.key)
					j++; //´Ó×óÏòÓÒÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×Ö´óÓÚtmp. keyµÄÔªËØR[i]
				R[i]=R[j]; //½«R[i]ºóÒÆµ½R&]µÄÎ»ÖÃ
			}
			R[j] = tmp; 	//TODO		
		}	
		QuickSort(R, s, i - 1, desc);
		QuickSort(R, i + 1, t, desc);
	}
}

int main()
{
	SqType a[MAX_SIZE];
	SqType b[MAX_SIZE];
	int n = 0, an = 0, bn = 0, m;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> m;
		if (m % 2 == 0) {
			a[an].key = a[an].data = m;
			an++;
		} else {
			b[bn].key = b[bn].data = m;
			bn++;
		}
	}
	QuickSort(b, 0, bn - 1, 0);
	QuickSort(a, 0, an - 1, 1);
	for (int i=0; i<bn; i++) {
		cout << b[i].key << " ";
	}
	for (int i=0; i<an; i++) {
		cout << a[i].key << " ";
	}
	return 0;
}

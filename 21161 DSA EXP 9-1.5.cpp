#include<iostream>
using namespace std;
#define MaxSize 1000
typedef int KeyType;
typedef int ElemType;

typedef struct{ 
	KeyType key;
	ElemType data;
}SqType;

void QuickSort(SqType R[ ] , int s, int t,int n){ //¶Ô R[s. . t]µÄÔªËØ½øÐÐµÝÔö¿ìËÙÅÅÐò
	int i=s,j=t;
	SqType tmp;
	if (s<t){       //Çø¼äÄÚÖÁÉÙ´æÔÚÁ½¸öÔªËØµÄÇé¿ö
		tmp=R[s];      //ÓÃÇø¼äµÄµÚ1¸öÔªËØ×÷Îª»ù×¼
		while (i!=j){     //´ÓÇø¼äÁ½¶Ë½»ÌæÏòÖÐ¼äÉ¨Ãè£¬Ö±ÖÁi=jÎªÖ¹
			while (j>i&& R[j].key>=tmp.key)
				j--; //´ÓÓÒÏò×óÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×ÖÐ¡ÓÚtmp. keyµÄR[j]
			R[i] =R[j]; //½«RCflÇ°ÒÆµ½R[i]µÄÎ»ÖÃ
			while (i<j && R[i].key<=tmp.key)
				i++; //´Ó×óÏòÓÒÉ¨Ãè£¬ÕÒµÚ1¸ö¹Ø¼ü×Ö´óÓÚtmp. keyµÄÔªËØR[i]
			R[j]=R[i]; //½«R[i]ºóÒÆµ½R&]µÄÎ»ÖÃ
			
		}
		R[i] = tmp; 
		
		for(int k=0;k<n;k++){
			cout<<R[k].key<<" ";
		}
		cout<<endl;
		
		QuickSort(R, s, i-1,n); //¶Ô×ó×ÓÐòÁÐµÝ¹éÅÅÐò
		QuickSort(R, i+1, t,n); //¶ÔÓÒ×ÓÐòÁÐµÝ¹éÅÅÐò
		
		
	}
}

int main(){
	SqType R[10];
	int n=10;
	for(int i=0;i<n;i++){
		cin>>R[i].key;
	}
	
	QuickSort(R,0,n-1,n);
	return 0;
}

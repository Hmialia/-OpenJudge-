#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
} SLinkNode;

void InitList(SLinkNode *&L)
{
	L = (SLinkNode *)malloc(sizeof(SLinkNode));
	L->next = NULL;
}

void DispList(SLinkNode *L)
{
	SLinkNode *p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void DestroyList(SLinkNode *&L)
{
	SLinkNode *pre = L, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

void CreateList(SLinkNode *&L, ElemType a[], int n)
{
	SLinkNode *tc = L;
	for (int i=0; i<n; i++) {
		SLinkNode *s = (SLinkNode *)malloc(sizeof(SLinkNode));
		s->data = a[i];
		tc->next = s;
		s->next = NULL;
		tc = s;
	}
}
void DelAll7(SLinkNode *&L){
	SLinkNode *pre = L, *p = pre->next;
	while (p != NULL) {
		if(p->data%7==0||p->data%10==7||p->data/10==7){
			pre->next=p->next;
			p=pre->next;
		}
		else{
			pre = p;
			p = p->next;			
		}
	}	
}
int main(void)
{
	SLinkNode *L;
	InitList(L);
	int n;
	ElemType a[MAXSIZE];
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	CreateList(L, a, n);
	DelAll7(L);
	DispList(L);
	DestroyList(L);
	return 0;
}

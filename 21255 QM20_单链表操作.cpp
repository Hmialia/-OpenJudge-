#include <malloc.h>
#include <iostream>
using namespace std;

typedef int ElemType;
#define MAX_SIZE 100

typedef struct node
{
	ElemType data;		//数据域
	struct node *next;	//指针域
} SLinkNode;	//单链表结点类型

void CreateListR(SLinkNode *&L, ElemType a[], int n)//尾插法建表
{
	SLinkNode *s, *tc;  int i;
	L = (SLinkNode *)malloc(sizeof(SLinkNode));	
	tc = L;				
	for (i = 0; i < n; i++)
	{
		s = (SLinkNode *)malloc(sizeof(SLinkNode));
		s->data = a[i];				
		tc->next = s;		
		tc = s;
	}
	tc->next = NULL;		
}
void Insertbeforex(SLinkNode *L,ElemType x){
	SLinkNode *pre = L, *p = pre->next;
	ElemType min=p->data;
	while (p != NULL) {
		if(p->data<min){
			min=p->data;
			SLinkNode *s = (SLinkNode *)malloc(sizeof(SLinkNode));
			s->data=x;
			pre->next=s;
			s->next=p;
		}
		else{
			pre = p;
			p = p->next;			
		}
	}
	pre = L, p = L->next;
	if(min==p->data){
		SLinkNode *s = (SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;
		pre->next=s;
		s->next=p;
	}
}

void DispList(SLinkNode *L)	//输出单链表
{
	SLinkNode *p = L->next;
	while (p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
void DestroyList(SLinkNode *&L)	//销毁单链表L
{
	SLinkNode *pre = L, *p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;			
	}
	free(pre);
}
int main()
{	
	ElemType a[MAX_SIZE];	
	SLinkNode *L;
	int nlength,x;
	cin >> nlength;
	for (int i = 0; i < nlength; i++) 
		cin >> a[i];
	CreateListR(L, a, nlength);
	cin>>x;
	Insertbeforex(L,x);
	DispList(L);
	DestroyList(L);
	return 0;
	
}

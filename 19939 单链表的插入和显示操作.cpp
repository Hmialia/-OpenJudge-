#include <malloc.h>
#include <iostream>
using namespace std;

typedef int ElemType;
#define MAX_SIZE 100

typedef struct node
{
	ElemType data;					//数据域
	struct node *next;				//指针域
} SLinkNode;						//单链表结点类型

void CreateListR(SLinkNode *&L, ElemType a[], int n)	//尾插法建表
{
	SLinkNode *s, *tc;  int i;
	L = (SLinkNode *)malloc(sizeof(SLinkNode));		//创建头结点
	tc = L;											//tc为L的尾结点指针
	for (i = 0; i < n; i++)
	{
		s = (SLinkNode *)malloc(sizeof(SLinkNode));
		s->data = a[i];								//创建存放a[i]元素的新结点s
		tc->next = s;									//将s结点插入tc结点之后
		tc = s;
	}
	tc->next = NULL;									//尾结点next域置为NULL
}

int InsElemSpe(SLinkNode *&L)	//插入结点
{
	SLinkNode *s,*p=L,*maxp;
	ElemType max=p->next->data;
	while(p!=NULL){
		if(p->data>max){
			max=p->data;
			maxp=p;
		}
		p=p->next;
	}
	//	cout<<"max="<<max<<endl;
	s=(SLinkNode *)malloc(sizeof(SLinkNode));
	s->data=max+10;
	s->next=maxp->next;
	maxp->next=s;
	
	return 1;					//插入运算成功,返回1
	
}

void DispList(SLinkNode *L)			//输出单链表
{
	SLinkNode *p = L->next;
	while (p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
void DestroyList(SLinkNode *&L)		//销毁单链表L
{
	SLinkNode *pre = L, *p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;			//pre、p同步后移
	}
	free(pre);
}
int main()
{
	
	
	ElemType a[MAX_SIZE];
	
	SLinkNode *L;
	int nlength;
	cin >> nlength;
	for (int i = 0; i < nlength; i++) 
		cin >> a[i];
	
	
	CreateListR(L, a, nlength);
	InsElemSpe(L);
	DispList(L);
	DestroyList(L);
	return 0;
	
}

#include <malloc.h>
#include <stdio.h>
#include<iostream>
using namespace std;
const int MAXSIZE=100;
typedef char ElemType;
typedef struct node{
	ElemType data;					//数据域
	struct node *next;				//指针域
} SLinkNode;						//单链表结点类型

void InitList(SLinkNode *&L)					//初始化单链表L
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//创建头结点L
	L->next=L;
}

void DestroyList(SLinkNode *&L)		//销毁单链表L
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{	free(pre);
		pre=p; p=p->next;			//pre、p同步后移
	}
	free(pre);
}
int GetLength(SLinkNode *L)			//求循环链表长度
{	int i=0;
	SLinkNode *p=L->next;
	while (p!=L)
	{	i++;
		p=p->next;
	}
	return i;
}

void DispList(SLinkNode *L)			//输出循环链表
{	SLinkNode *p=L->next;
	while (p!=L)
	{	cout<<p->data<<" ";
		p=p->next;
	}
	printf("\n");
}

void CreateListR(SLinkNode *&L,ElemType a[],int n)	//尾插法建循环表
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//创建头结点
	tc=L;											//tc为L的尾结点指针
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];								//创建存放a[i]元素的新结点s
		tc->next=s;									//将s结点插入tc结点之后
		tc=s;
	}
	tc->next=L;									//尾结点next域置为NULL
}

bool Isempty(SLinkNode *&L){                                //判断循环单链表L是否为空；
	return L->next==L;
}

int GetElem(SLinkNode *L,int i,ElemType &e)	//求循环单链表第i个结点值
{	int j=1;
	SLinkNode *p=L->next;					//p指向头结点，计数器j置为0
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i)
	{	j++;
		p=p->next;
	}
	if (p==L)
		return 0;					//未找到返回0
	else
	{	e=p->data;
		return 1;					//找到后返回1
	}
}

int Locate(SLinkNode *L,ElemType e)	//求环单链表第一个值为e的结点位置
{	SLinkNode *p=L->next;
	int j=1;						//p指向第一个数据结点，j置为其序号1
	while (p!=L && p->data!=e)
	{	p=p->next;
		j++;
	}
	if (p==L) return(0);			//未找到返回0
	else return(j);					//找到后返回其序号
}

int InsElem(SLinkNode *&L,ElemType x,int i)	//循环单链表插入结点值为x的结点
{	int j=1;
	SLinkNode *p=L->next,*s;
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i-1)		//查找第i-1个结点p
	{	j++;
		p=p->next;
	}
	if (p==L)
		return 0;					//未找到第i-1个结点时返回0
	else							//找到第i-1个结点p
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;					//创建存放元素x的新结点s
		s->next=p->next;			//将s结点插入到p结点之后
		p->next=s;
		return 1;					//插入运算成功,返回1
	}
}

int DelElem(SLinkNode *&L,int i)	//删除循环单链表结点
{	int j=1;
	SLinkNode *p=L->next,*q;
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i-1)		//查找第i-1个结点
	{	j++;
		p=p->next;
	}
	if (p==L)
		return 0;					//未找到第i-1个结点时返回0
	else							//找到第i-1个结点p
	{	q=p->next;					//q指向被删结点
		if (q==L)
			return 0;				//没有第i个结点时返回0
		else
		{	p->next=q->next;		//从单链表中删除q结点
			free(q);				//释放其空间
			return 1;
		}
	}
}

int main()
{
	SLinkNode *L;
	InitList(L);
	bool fl=L->next==L;
	cout<<fl<<endl;                 //（1）初始化循环单链表L，输出(L->next==L)的逻辑值；
	int n;
	ElemType a[MAXSIZE];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	CreateListR(L,a,n);				//（2）依次采用尾插法插入元素
	DispList(L);                    //（3）输出循环单链表L；
	cout<<GetLength(L)<<endl;       //（4）输出循环单链表L的长度；
	
	if(Isempty(L)){                 //（5）判断循环单链表L是否为空；
		cout<<"yes\n";
	}
	else{
		cout<<"no\n";
	}
	
	ElemType e;
	GetElem(L,3,e);
	cout<<e<<endl;                  //（6）输出循环单链表L的第3个元素；
	
	cout<<Locate(L,'a')<<endl;      //（7）输出元素a的位置；
	
	InsElem(L,'w',4);               //（8）在第4个元素位置上插入‘w’元素；
	
	DispList(L);                    //（9）输出循环单链表L；
	
	DelElem(L,5);                    //（10）删除L的第5个元素；
	
	DispList(L); 
	
	DestroyList(L);
	return 0; 
}

#include <malloc.h>
#include <iostream>
using namespace std;

typedef struct node
{
	int no;			//小孩编号
	struct node *next;		//指向下一个结点指针
} Child;

void CreateList(Child *&L, int n) //建立有n个结点的循环单链表
{
	int i;  Child *p, *tc;	//tc指向新建循环单链表的尾结点
	L = (Child *)malloc(sizeof(Child));
	L->no = 1;			//先建立只有一个no为1结点的单链表
	tc = L;
	for (i = 2; i <= n; i++)
	{
		p = (Child *)malloc(sizeof(Child));
		p->no = i;		//建立一个存放编号i的结点
		tc->next = p; tc = p;	//将p结点链到末尾
	}
	tc->next = L;			//构成一个首结点为L的循环单链表
}
void Joseph(int n)  //求解约瑟夫序列
{
	int i, j;  Child *L, *p, *q;
	CreateList(L, n);
	int m = 5;
	p=L;
	
	while(p->next!=p){
		for(int i=1;i<m-1;i++){
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		free(q);
		p=p->next;
	}
	
	cout<<p->no<<endl;
}
int main()
{
	int n;
	cin>> n;
	Joseph(n);
	system("pause");
	return 0;
}

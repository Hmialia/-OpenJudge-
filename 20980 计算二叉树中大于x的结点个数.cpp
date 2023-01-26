#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
#include <stdio.h>
typedef struct tnode{ 
	ElemType data;
	struct tnode * lchild, * rchild;
} BTNode;

int CalcGreaterNodes(BTNode * bt,ElemType x){
	if (bt==NULL){
		return 0;
	}
	else if(bt->data>x){
		cout<<bt->data;
		return 1+CalcGreaterNodes(bt->lchild,x)+CalcGreaterNodes(bt->rchild,x);
	}
	else {
		return CalcGreaterNodes(bt->lchild,x)+CalcGreaterNodes(bt->rchild,x);
	} 
}
void CreateBTree(BTNode * &bt,char *str)	//由括号表示串创建二叉链
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			
	ch=str[j];
	while (ch!='\0')	
	{	switch(ch)
		{
			case '(':top++;St[top]=p;k=1; break;	
			case ')':top--;break;
			case ',':k=2; break;
			default:p=new BTNode();
			p->data=ch;p->lchild=p->rchild=NULL;
			if (bt==NULL)
				bt=p;
			else		
			{	switch(k) 
				{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
				}
			}
		}
		j++;
		ch=str[j];
	}
}
void DestroyBTree(BTNode *&bt)		//销毁二叉树
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		delete bt;
	}
}
int main()
{
	char btree[MaxSize];
	cin>>btree;
	char x;
	cin>>x;	
	BTNode *bt;
	CreateBTree(bt,btree);		
	int n=CalcGreaterNodes(bt,x);
	cout<<n<<endl;
	DestroyBTree(bt);
	return 0;
}

#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;

typedef struct tnode
{	ElemType data;					
	struct tnode *lchild,*rchild;	
} BTNode;	

void CreateBTree(BTNode * &bt,char *str)//由括号表示串创建二叉链
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')	//str未扫描完时循环
	{	switch(ch)
		{
			case '(':top++;St[top]=p;k=1; break;//为左孩子结点
			case ')':top--;break;
			case ',':k=2; break;	//为右孩子结点
			default:p=new BTNode();
			p->data=ch;p->lchild=p->rchild=NULL;
			if (bt==NULL)	//*p为二叉树的根结点
				bt=p;
			else			//已建立二叉树根结点
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
void DestroyBTree(BTNode *&bt)		//销毁二叉链
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		delete bt;
	}
}
void PreOrder(BTNode *&bt){
	if(bt!=NULL){
		cout<<bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
	else return;	
}

void InOrder(BTNode *&bt){
	if(bt!=NULL){
		InOrder(bt->lchild);
		cout<<bt->data;
		InOrder(bt->rchild);
	}
	else return;		
}

void PostOrder(BTNode *&bt){
	if(bt!=NULL){
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data;
	}
	else return;		
}
int main()
{
	char tree[MaxSize];
	cin>>tree;
	BTNode *bt;
	CreateBTree(bt,tree);
	PreOrder(bt);cout<<endl;
	InOrder(bt);cout<<endl;
	PostOrder(bt);cout<<endl;
	DestroyBTree(bt);
	return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
#define MaxSize 100
typedef char ElemType;

typedef struct tnode{ 
	ElemType data;
	struct tnode * lchild, * rchild;
} BTNode;

int Sum(BTNode * b){       //求二叉树b中所有结点值之和
	if (b==NULL) return 0;
	else return(b-> data+ Sum(b->lchild) +Sum(b->rchild));
}

void CreateBTree(BTNode * &bt,char *str)	//由括号表示串创建二叉链
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')	//str未扫描完时循环
	{	switch(ch)
		{
			case '(':top++;St[top]=p;k=1; break;	//为左孩子结点
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

void DestroyBTree(BTNode * &bt){   //销毁二叉树bt
	if(bt!= NULL){ 
		DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}

int BTHeight(BTNode * bt){//求二叉树高度
	int lchilddep, rchilddep;
	if (bt==NULL) return(0); //空树的高度为 0
	else{ 
		lchilddep=BTHeight(bt-> lchild); //求左子树的高度为 Ichilddep
		rchilddep=BTHeight(bt-> rchild); //求右子树的高度为 rchilddep
		return (lchilddep>rchilddep)?(lchilddep+1) : (rchilddep+1);
	}
}

int NodeCount(BTNode * bt){ //求二叉树结点个数
	int num1, num2;
	if (bt==NULL)
		return 0;
	else{ 
		num1 = NodeCount( bt->lchild);
		num2= NodeCount(bt-> rchild);
		return(num1+num2+1);
	}
}

int LeafCount( BTNode * bt){  //求二叉树叶子结点个数
	int num1, num2 ;
	if (bt==NULL)
		return 0;
	else if (bt-> lchild==NULL && bt-> rchild==NULL)
		return 1;
	else{ 
		num1 =LeafCount(bt-> lchild);
		num2= LeafCount(bt->rchild);
		return (num1+num2);
	}
}

void DispBTree(BTNode * bt){ //以括号表示法输出二叉树
	if (bt!=NULL){
		printf("%c", bt->data);
		if (bt-> lchild!= NULL||bt-> rchild!= NULL){
			printf("("); DispBTree(bt->lchild);
			if(bt-> rchild!= NULL)
				printf(",");
			DispBTree(bt->rchild);
			printf(")");
		}
	}
}

void Dislevel(BTNode * bt){
	static int level=1;
	
	if (bt!=NULL){
		cout<<level<<" ";
		if (bt-> lchild!= NULL||bt-> rchild!= NULL){
			level++; Dislevel(bt->lchild);
			if(bt-> rchild!= NULL) Dislevel(bt->rchild);
			level--;
		}
	}	
}

int main()
{
	char tree[MaxSize];
	cin>>tree;        // 输入二叉树的括号表示法
	BTNode *bt;
	CreateBTree(bt,tree);
	
	Dislevel(bt);	cout<<endl;  // 输出二叉树
	
	DestroyBTree(bt);
	return 0;
}

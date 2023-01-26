#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
#include <stdio.h>
typedef struct tnode{ 
	ElemType data;
	struct tnode * lchild, * rchild;
} BTNode;

int Sum(BTNode * b){       //Çó¶þ²æÊ÷bÖÐËùÓÐ½áµãÖµÖ®ºÍ
	if (b==NULL) return 0;
	else return(b-> data+ Sum(b->lchild) +Sum(b->rchild));
}
void DestroyBTree(BTNode * &bt){   //Ïú»Ù¶þ²æÊ÷bt
	if(bt!= NULL){ 
		DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}

int BTHeight(BTNode * bt){//Çó¶þ²æÊ÷¸ß¶È
	int lchilddep, rchilddep;
	if (bt==NULL) return(0); //¿ÕÊ÷µÄ¸ß¶ÈÎª 0
	else{ 
		lchilddep=BTHeight(bt-> lchild); //Çó×ó×ÓÊ÷µÄ¸ß¶ÈÎª Ichilddep
		rchilddep=BTHeight(bt-> rchild); //ÇóÓÒ×ÓÊ÷µÄ¸ß¶ÈÎª rchilddep
		return (lchilddep>rchilddep)?(lchilddep+1) : (rchilddep+1);
	}
}

int NodeCount(BTNode * bt){ //Çó¶þ²æÊ÷½áµã¸öÊý
	int num1, num2;
	if (bt==NULL)
		return 0;
	else{ 
		num1 = NodeCount( bt->lchild);
		num2= NodeCount(bt-> rchild);
		return(num1+num2+1);
	}
}

int LeafCount( BTNode * bt){  //Çó¶þ²æÊ÷Ò¶×Ó½áµã¸öÊý
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

void DispBTree(BTNode * bt){ //ÒÔÀ¨ºÅ±íÊ¾·¨Êä³ö¶þ²æÊ÷
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

int main()
{
	char tree[MaxSize];
	cin>>tree;
	BTNode *bt;
	CreateBTree(bt,tree);
	DispBTree(bt);	cout<<endl;
	cout<<BTHeight(bt)<<" "<<NodeCount(bt)<<" "<<LeafCount(bt);
	DestroyBTree(bt);
	return 0;
}

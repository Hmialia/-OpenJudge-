#include <iostream>
#include <stdio.h>
using namespace std;
#define MaxSize 100
typedef char BTelemtype;

typedef struct tnode{ 
	BTelemtype data;
	bool levelend=0;
	struct tnode * lchild, * rchild;
} BTNode;


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


typedef BTNode * SQelemtype;			//假设顺序队中所有元素为int类型
typedef struct
{	SQelemtype data[MaxSize];		//保存队中元素
	int front,rear;				//队头和队尾指针
} SqQueue;


void InitQueue(SqQueue &sq)		//初始化队列
{
	sq.rear=sq.front=0;			//指针初始化
}

void DestroyQueue(SqQueue sq)  //销毁队列
{    }

int EnQueue(SqQueue &sq,SQelemtype x)//进队
{	if ((sq.rear+1) % MaxSize==sq.front)	//队满上溢出
	return 0;
	sq.rear=(sq.rear+1) % MaxSize;			//队尾循环进1
	sq.data[sq.rear]=x;
	return 1;
}

int GetHead(SqQueue sq,SQelemtype &x){//取队头元素
	if(sq.rear==sq.front)
		return 0;
	x=sq.data[(sq.front+1)%MaxSize];
	return 1;
}

int DeQueue(SqQueue &sq,SQelemtype &x)		//出队
{	if (sq.rear==sq.front)					//队空下溢出
	return 0;
	sq.front=(sq.front+1) % MaxSize;		//队头循环进1
	x=sq.data[sq.front];
	return 1;
}

int QueueEmpty(SqQueue sq)//判断队空
{	if (sq.rear==sq.front) return 1;
	else return 0;
}

int CountNumber(SqQueue sq){
	return  (sq. rear-sq. front+ MaxSize) % MaxSize;
}


void DisElemevel(BTNode * bt){ 
	BTNode *p=NULL; 
	SqQueue sq;InitQueue(sq);
	bt->levelend=1;
	
	BTNode *n=new BTNode;
	n->data='#'; n->lchild==NULL; n->rchild=NULL;
	
	EnQueue(sq,bt);
	
	while (!QueueEmpty(sq)){ 
		DeQueue(sq,p);
		if(p->levelend){
			if (p->rchild!=NULL){ 
				p->rchild->levelend=1;
			}
			else if (p->lchild!=NULL){ 
				p->lchild->levelend=1;
			}
			else;
		}
		cout<<p->data<<" ";
		if (p->lchild!=NULL){ 
			EnQueue(sq,p->lchild);
		}
		if (p-> rchild!=NULL){ 
			EnQueue(sq,p->rchild);
		}
		if(p->levelend) cout<<endl;
	}
}


int main()
{
	char tree[MaxSize];
	cin>>tree;      
	BTNode *bt;
	CreateBTree(bt,tree);
	DisElemevel(bt);
	DestroyBTree(bt);
	return 0;
}

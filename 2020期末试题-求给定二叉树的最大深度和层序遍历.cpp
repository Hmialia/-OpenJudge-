#include <iostream>
#include <queue>
#define elemType char
using namespace std;
struct BTNode{
	elemType data;
	BTNode *lchild, *rchild;
};
void CreateBTree(BTNode *&bt,char *str){
	BTNode *St[1000],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;
	ch=str[j];
	while (ch!='\0'){
		switch (ch) {
			case '(':top++;St[top]=p;k=1;break;
			case ')':top--;break;
			case ',':k=2;break;
			default:p=new BTNode();
			p->data=ch;
			p->rchild=p->lchild=NULL;
			if(bt==NULL)
			{
				bt=p;
			}
			else
			{
				switch (k) {
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
				}
			}
		}
		j++;
		ch=str[j];
	}
}

void DestoryBTree(BTNode *&bt){
	if(bt!=NULL){
		DestoryBTree(bt->lchild);
		DestoryBTree(bt->rchild);
		delete bt;
	}
}
// 在此处补充你的代码
#define MaxSize 1000

void LevelOrder(BTNode * bt){ 
	BTNode * p;
	BTNode * qu[MaxSize];
	int front, rear;
	front=rear=0;
	rear++ ; qu [rear] = bt;
	while (front!=rear){ 
		front= (front+1) %MaxSize;
		p=qu [front];
		printf("%c ", p-> data);
			if (p-> lchild!=NULL)
			{ rear= (rear+1) % MaxSize;
				qu [rear] = p-> lchild;
			}
			if (p-> rchild!=NULL)
			{ rear= (rear+ 1) % MaxSize;
				qu[rear] =p-> rchild;
			}
	}
}

int MaxDepth(BTNode * bt){
	int lch, rch;
	if (bt==NULL) return(0);
	else{
		lch=MaxDepth(bt-> lchild);
		rch=MaxDepth(bt-> rchild);
		return (lch>rch)?(lch+1):(rch+1);
	}
}

int main()
{
	char str[1000];
	cin>>str;
	BTNode *bt=new BTNode();
	CreateBTree(bt,str);
	cout << MaxDepth(bt)<<endl;
	LevelOrder(bt);
	DestoryBTree(bt);
	return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 100

typedef char ElemType;
typedef struct tnode
{
	ElemType data;
	struct tnode *lchild,*rchild;
} BTNode;

void CreatBTree(BTNode *&bt, char *str)
{
	BTNode *St[MAX_SIZE], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	bt = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
			case '(': top++; St[top] = p; k = 1; break;
			case ')': top--; break;
			case ',': k=2; break;
			default: 
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch; 
			p->lchild = p->rchild = NULL;
			if (bt == NULL) 
				bt=p;
			else {
				switch (k) {
					case 1: St[top]->lchild = p; break;
					case 2: St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

int BTreeSearch(BTNode *btree, char ch) 
{
	static bool fff = 0;
	
	if(fff)					return 1;
	else if(btree==NULL) 	return 0;
	else if(btree->data==ch){
		cout<<ch<<endl;
		fff=1;
		return 1;
	}
	else {
		cout<<btree->data<<" ";
		BTreeSearch(btree->lchild,ch);
		BTreeSearch(btree->rchild,ch);
		return 0;
	}
}

int main(void)
{
	BTNode *bt;
	char str[MAX_SIZE];
	cin >> str;
	CreatBTree(bt, str);
	char ch;
	cin >> ch;
	BTreeSearch(bt, ch);
	return 0;
}

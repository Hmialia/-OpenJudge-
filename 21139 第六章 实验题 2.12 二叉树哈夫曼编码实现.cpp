#include <iostream>
#include <cstring>
#include <stack>
#define MaxSize 100

using namespace std;

struct BTNode{
	int q=-1,dep=1;
	char data,c;
	BTNode *lc,*rc;
};

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
			p->data=ch;p->lc=p->rc=NULL;
			if (bt==NULL)	//*p为二叉树的根结点
				bt=p;
			else			//已建立二叉树根结点
			{	switch(k) 
				{
					case 1:St[top]->lc=p;break;
					case 2:St[top]->rc=p;break;
				}
			}
		}
		j++;
		ch=str[j];
	}
}

BTNode *saveLeaf[MaxSize];
int h=0; 
void SearchHHc(BTNode* bt){
	if(bt!=NULL){
		if(bt->lc==NULL&&bt->rc==NULL){
			saveLeaf[h]=bt;
			h++;
			return;
		}
		SearchHHc(bt->lc);
		SearchHHc(bt->rc);
	}
}

void Msdlev(BTNode *bt,int dep){
	if(bt!=NULL){
		bt->dep=dep;
		dep++;
		Msdlev(bt->lc,dep);
		Msdlev(bt->rc,dep);
	}
}
BTNode *PutifHHc[MaxSize];
int hn=0; 
void SearcifHH(BTNode *bt,int Dep){
	if (bt!=NULL){
		if(bt->dep==Dep&&(bt->lc!=NULL||bt->rc!=NULL)){
			PutifHHc[hn]=bt;
			hn++;
		}
		SearcifHH(bt->lc,Dep);
		SearcifHH(bt->rc,Dep);
	}
}

int HHcdo(BTNode *bt){
	int num1,num2;
	if(bt==NULL)
		return 0;
	else if(bt->lc==NULL&&bt->rc==NULL)
		return 1;
	else{
		num1=HHcdo(bt->lc);
		num2=HHcdo(bt->rc);
		return num1+num2;
	}
}

int BTHeight(BTNode *bt){
	int lch, rch; 
	if(bt==NULL) return 0; 
	else{
		lch=BTHeight(bt->lc); 
		rch=BTHeight(bt->rc); 
		if(lch>rch)return lch+1;
		else return rch+1;
	}
}

void giveQ(BTNode *&bt){
	if(bt!=NULL&&bt->lc!=NULL&&bt->rc!=NULL){
		bt->q=bt->lc->q+bt->rc->q;
		giveQ(bt->lc);
		giveQ(bt->rc);
	}
}
void printSTA(stack<int> s){ 
	int a[MaxSize],h=0;
	while (!s.empty())
		a[h++]=s.top(),s.pop();
	for(int i=h-1;i>=0;i--)
		cout<<a[i];
	cout<<" ";
}

stack<int> ans; 
void printHFM(BTNode *bt,char tag){
	if(bt!=NULL){
		if(bt->lc==NULL&&bt->rc==NULL&&bt->data!=tag){
			return;
		}
		if(bt->data==tag){
			printSTA(ans); 
			return;
		}
		ans.push(0);
		printHFM(bt->lc,tag);
		ans.pop(); 
		ans.push(1);
		printHFM(bt->rc,tag);
		ans.pop(); 
	}
}

void DestoryBTree(BTNode *&bt){
	if(bt!=NULL){
		DestoryBTree(bt->lc);
		DestoryBTree(bt->rc);
		delete bt;
	}
}

int main()
{
	int m[MaxSize];
	char str[MaxSize],bcs[MaxSize];
	BTNode *bt=new BTNode();
	
	cin>>str;
	CreateBTree(bt,str);
	
	int n=HHcdo(bt);
	for(int i=0;i<n;i++)cin>>bcs[i];
	for(int i=0;i<n;i++)cin>>m[i];
	
	Msdlev(bt,1);
	int th=BTHeight(bt);
	for(int i=th;i>0;i--)SearcifHH(bt,i);
	for(int i=0;i<hn;i++)cout<<PutifHHc[i]->data<<" ";
	cout<<endl;
	
	SearchHHc(bt);
	for(int i=0;i<h;i++)saveLeaf[i]->q=m[i];
	for(int i=0;i<th;i++)giveQ(bt);
	for(int i=0;i<hn;i++)cout<<PutifHHc[i]->q<<" ";
	cout<<endl;
	
	for(int i=0;i<h;i++)cout<<saveLeaf[i]->data<<" ";
	cout<<endl;
	
	for(int i=0;i<h;i++)printHFM(bt,saveLeaf[i]->data);
	
	DestoryBTree(bt);
	return 0;
}

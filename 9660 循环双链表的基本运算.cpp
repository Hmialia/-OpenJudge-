#include <malloc.h>
#include <stdio.h>
#include<iostream>
using namespace std;
const int MAXSIZE=100;
typedef char ElemType;

typedef struct node
{	ElemType data;				
	struct node *next,*piror;
} DLinkNode;					

void InitList(DLinkNode*&L){
	L=(DLinkNode*)malloc(sizeof(DLinkNode));
	L->piror=L->next=L;	
}

void DestroyList(DLinkNode *&L)	
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{	free(pre);
		pre=p; p=p->next;	
	}
	free(pre);
}

int GetLength(DLinkNode *L){
	int i=0;
	DLinkNode *p=L->next;
	while (p!=L){
		i++;
		p=p->next;
	}
	return i;
}

int GetElem(DLinkNode *L,int i,ElemType &e){
	int j=1;
	DLinkNode *p=L->next;					//pÖ¸ÏòÍ·½áµã£¬¼ÆÊýÆ÷jÖÃÎª0
	if (i<=0) return 0;				//²ÎÊýi´íÎó·µ»Ø0
	while (p!=L && j<i)
	{	j++;
		p=p->next;
	}
	if (p==L)
		return 0;					//Î´ÕÒµ½·µ»Ø0
	else
	{	e=p->data;
		return 1;					//ÕÒµ½ºó·µ»Ø1
	}
}

int Locate(DLinkNode *L,ElemType e)	//Çó»·µ¥Á´±íµÚÒ»¸öÖµÎªeµÄ½áµãÎ»ÖÃ
{	DLinkNode *p=L->next;
	int j=1;						//pÖ¸ÏòµÚÒ»¸öÊý¾Ý½áµã£¬jÖÃÎªÆäÐòºÅ1
	while (p!=L && p->data!=e)
	{	p=p->next;
		j++;
	}
	if (p==L) return(0);			//Î´ÕÒµ½·µ»Ø0
	else return(j);					//ÕÒµ½ºó·µ»ØÆäÐòºÅ
}

int InsElem(DLinkNode* &L,ElemType x,int i){
	int j=1;
	DLinkNode* p=L->next,*pre,*s;
	if(i<=0)return 0;
	while(p!=L&&j<i){
		j++;
		p=p->next;
	}
	if(p==L&&i>j+1)return 0;
	else{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=x;					//´´½¨´æ·ÅÔªËØxµÄÐÂ½áµãs
		pre=p->piror;			//½«s½áµã²åÈëµ½p½áµãÖ®ºó
		s->piror=pre;
		pre->next=s;
		p->piror=s;
		s->next=p;
		return 1;				
	}
}

int DelElem(DLinkNode *&L,int i)
{	int j=1;
	DLinkNode *p=L->next,*pre;
	if (i<=0) return 0;			
	while (p!=L && j<i)	
	{	j++;
		p=p->next;
	}
	if (p==L)
		return 0;				
	else{
		pre=p->piror;			
		p->next->piror=pre;
		pre->next=p->next;
		free(p);
		return 1;
	}
}

bool Isempty(DLinkNode *&L){                                //ÅÐ¶ÏÑ­»·µ¥Á´±íLÊÇ·ñÎª¿Õ£»
	return L->next==L;
}

void CreateListR(DLinkNode *&L,ElemType a[],int n)	//Î²²å·¨½¨±í
{
	DLinkNode *tc,*s;
	
	L=(DLinkNode *)malloc(sizeof(DLinkNode));		//´´½¨Í·½áµã
	tc=L;
	for (int i=0;i<n;i++){
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];
		tc->next=s;
		s->piror=tc;	
		tc=s;
	}
	tc->next=L;
	L->piror=tc;
}

void DispList(DLinkNode *L)			//Êä³öÑ­»·Á´±í
{	DLinkNode *p=L->next;
	while (p!=L)
	{	cout<<p->data<<" ";
		p=p->next;
	}
	printf("\n");
}

int main()
{
	DLinkNode *L;
	InitList(L);                   //£¨1£©³õ³õÊ¼»¯Ñ­»·Ë«Á´±íh£»
	int n;
	ElemType a[MAXSIZE];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	CreateListR(L,a,n);			//£¨2£©ÒÀ´Î²ÉÓÃÎ²²å·¨²åÈëÔªËØ
	
	DispList(L);                 //£¨3£©Êä³öÑ­»·Ë«Á´±íh£»
	cout<<GetLength(L)<<endl;       //£¨4£©Êä³öÑ­»·Ë«Á´±íhµÄ³¤¶È£»
	
	if(Isempty(L)){                 //£¨5£©ÅÐ¶ÏÑ­»·Ë«Á´±íÊÇ·ñÎª¿Õ£»
		cout<<"yes\n";
	}
	else{
		cout<<"no\n";
	}
	
	ElemType e;
	GetElem(L,3,e);
	cout<<e<<endl;                  //£¨6£©Êä³öÑ­»·Ë«Á´±íhµÄµÚ3¸öÔªËØ£»
	
	cout<<Locate(L,'a')<<endl;      //£¨7£©Êä³öÔªËØaµÄÎ»ÖÃ£»
	
	InsElem(L,'f',4);               //£¨8£©ÔÚµÚ4¸öÔªËØÎ»ÖÃÉÏ²åÈë¡®f¡¯ÔªËØ£»
	
	DispList(L);                    //£¨9£©Êä³öÑ­»·Ë«Á´±íh£»
	
	DelElem(L,5);                    //£¨10£©É¾³ýLµÄµÚ5¸öÔªËØ£»
	
	DispList(L);                      // £¨11£©Êä³öÑ­»·Ë«Á´±íh£»
	
	DestroyList(L);
	return 0; 
}

#include <malloc.h>
#include <stdio.h>
#include<iostream>
using namespace std;
const int MAXSIZE=100;
typedef int ElemType;
typedef struct node
{	ElemType data;					//Êý¾ÝÓò
	struct node *next;				//Ö¸ÕëÓò
} SLinkNode;						//µ¥Á´±í½áµãÀàÐÍ
void InitList(SLinkNode *&L)					//³õÊ¼»¯µ¥Á´±íL
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//´´½¨Í·½áµãL
	L->next=NULL;
}
void DestroyList(SLinkNode *&L)		//Ïú»Ùµ¥Á´±íL
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;			//pre¡¢pÍ¬²½ºóÒÆ
	}
	free(pre);
}
int GetLength(SLinkNode *L)			//Çó³¤¶È
{	int i=0;
	SLinkNode *p=L->next;
	while (p!=NULL)
	{	i++;
		p=p->next;
	}
	return i;
}
int GetElem(SLinkNode *L,int i,ElemType &e)	//ÇóµÚi¸ö½áµãÖµ
{	int j=0;
	SLinkNode *p=L;					//pÖ¸ÏòÍ·½áµã£¬¼ÆÊýÆ÷jÖÃÎª0
	if (i<=0) return 0;				//²ÎÊýi´íÎó·µ»Ø0
	while (p!=NULL && j<i)
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;					//Î´ÕÒµ½·µ»Ø0
	else
	{	e=p->data;
		return 1;					//ÕÒµ½ºó·µ»Ø1
	}
}
int Locate(SLinkNode *L,ElemType e)	//ÇóµÚÒ»¸öÖµÎªeµÄ½áµãÎ»ÖÃ
{	SLinkNode *p=L->next;
	int j=1;						//pÖ¸ÏòµÚÒ»¸öÊý¾Ý½áµã£¬jÖÃÎªÆäÐòºÅ1
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		j++;
	}
	if (p==NULL) return(0);			//Î´ÕÒµ½·µ»Ø0
	else return(j);					//ÕÒµ½ºó·µ»ØÆäÐòºÅ
}
int InsElem(SLinkNode *&L,ElemType x,int i)	//²åÈë½áµãÖµÎªxµÄ½áµã
{	int j=0;
	SLinkNode *p=L,*s;
	if (i<=0) return 0;				//²ÎÊýi´íÎó·µ»Ø0
	while (p!=NULL && j<i-1)		//²éÕÒµÚi-1¸ö½áµãp
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;					//Î´ÕÒµ½µÚi-1¸ö½áµãÊ±·µ»Ø0
	else							//ÕÒµ½µÚi-1¸ö½áµãp
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;					//´´½¨´æ·ÅÔªËØxµÄÐÂ½áµãs
		s->next=p->next;			//½«s½áµã²åÈëµ½p½áµãÖ®ºó
		p->next=s;
		return 1;					//²åÈëÔËËã³É¹¦,·µ»Ø1
	}
}
int DelElem(SLinkNode *&L,int i)	//É¾³ý½áµã
{	int j=0;
	SLinkNode *p=L,*q;
	if (i<=0) return 0;				//²ÎÊýi´íÎó·µ»Ø0
	while (p!=NULL && j<i-1)		//²éÕÒµÚi-1¸ö½áµã
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;					//Î´ÕÒµ½µÚi-1¸ö½áµãÊ±·µ»Ø0
	else							//ÕÒµ½µÚi-1¸ö½áµãp
	{	q=p->next;					//qÖ¸Ïò±»É¾½áµã
		if (q==NULL)
			return 0;				//Ã»ÓÐµÚi¸ö½áµãÊ±·µ»Ø0
		else
		{	p->next=q->next;		//´Óµ¥Á´±íÖÐÉ¾³ýq½áµã
			free(q);				//ÊÍ·ÅÆä¿Õ¼ä
			return 1;
		}
	}
}
void DispList(SLinkNode *L)			//Êä³öµ¥Á´±í
{	SLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void CreateListF(SLinkNode *&L,ElemType a[],int n)	//Í·²å·¨½¨±í
{	SLinkNode *s;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//´´½¨Í·½áµã
	L->next=NULL;									//Í·½áµãµÄnextÓòÖÃ¿Õ
	for (i=0;i<n;i++)								//±éÀúaÊý×éËùÓÐÔªËØ
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];								//´´½¨´æ·Åa[i]ÔªËØµÄÐÂ½áµãs
		s->next=L->next;							//½«s²åÔÚÍ·½áµãÖ®ºó
		L->next=s;
	}
}

void CreateListR(SLinkNode *&L,ElemType a[],int n)	//Î²²å·¨½¨±í
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//´´½¨Í·½áµã
	tc=L;											//tcÎªLµÄÎ²½áµãÖ¸Õë
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];								//´´½¨´æ·Åa[i]ÔªËØµÄÐÂ½áµãs
		tc->next=s;									//½«s½áµã²åÈëtc½áµãÖ®ºó
		tc=s;
	}
	tc->next=NULL;									//Î²½áµãnextÓòÖÃÎªNULL
}


int main(){
	ElemType a[MAXSIZE],b;
	int n=0;
	while (~scanf("%d", &b)) {
		a[n++] = b;
	}
	
	SLinkNode *L;
	CreateListR(L,a,n);
	
	DispList(L);
	
	DelElem(L,1);
	DispList(L);
	
	cout<<GetLength(L)<<endl;
	
	InsElem(L,100,2);
	
	DispList(L);
	
	cout<<Locate(L,100);
	
	DestroyList(L);
	return 0; 
}

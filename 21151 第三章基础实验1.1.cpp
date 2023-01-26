#include<iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;
# define MaxSize 100
typedef char ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &st){
	st.top=-1;
}

void DestroyStack(SqStack st)
{ }

int Push(SqStack &st,ElemType x){
	if (st. top==MaxSize-1)
		return 0;
	else{ 
		st.top++ ;
		st.data[st.top]=x;
		return 1; 
	}
}

int Pop(SqStack &st,ElemType &x){
	if (st.top==-1)
		return 0;
	else{ 
		x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st, ElemType &x){
	if (st.top==-1)
		return 0;
	else{ 
		x=st.data[st.top];
		return 1; 
	}
}

int StackEmpty(SqStack st){ 
	if(st.top==-1) return 1;
	else return 0;
}

int main(){
	SqStack st;
	InitStack(st);
	
	if(StackEmpty(st))cout<<"Yes\n";
	else cout<<"No\n";
	
	ElemType b;
	//	while(~scanf("%c",&b)){
	//		Push(st,b);
	//	}
	
	for(int i=0;i<4;i++){
		cin>>b;
		Push(st,b);
	}
	
	GetTop(st,b);
	cout<<b<<"\n";
	
	while(!StackEmpty(st)){
		Pop(st,b);
		cout<<b<<" ";
	}	
	cout<<"\n";
	
	return 0;
}

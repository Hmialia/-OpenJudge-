#include<iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;
# define MaxSize 11000
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

void Brackets(ElemType* br){
	SqStack st;
	InitStack(st);
	ElemType x='?';
	int flag=0,flag2=0;
	int i=0;
	while(br[i]!='\0'&&!flag){
		if(br[i]=='('||br[i]=='['||br[i]=='{'){
			Push(st,br[i]);	
		}
		else if(br[i]=='}'){
			flag2=!Pop(st,x);
			if(flag2){
				cout<<"No\n";
				return;
				break;
				
			}
			if(x!='{'){
				cout<<"No\n";
				return;
				break;
				
			}
		}
		else if(br[i]==']'){
			flag2=!Pop(st,x);
			if(flag2){
				cout<<"No\n";
				return;
				break;
				
			}			
			if(x!='['){
				cout<<"No\n";
				return;
				break;
				
			}
		}
		else if(br[i]==')'){
			flag2=!Pop(st,x);
			if(flag2){
				cout<<"No\n";
				return;
				break;
				
			}			
			if(x!='('){
				cout<<"No\n";
				return;
				break;
				
			}
		}
		i++;
	}
	if(!StackEmpty(st)){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
}

int main(){
	ElemType a[MaxSize];
	cin>>a;
	
	Brackets(a);
	
	return 0;
}

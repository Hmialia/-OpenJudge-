#include<iostream>
#include<string.h>
using namespace std;

#define MAX_SIZE 100

typedef char ElemType;
typedef struct {	
	ElemType data[MAX_SIZE];
	int top;
} SqStack;

void InitStack(SqStack &st)
{
	st.top=-1;
}

int PushStack(SqStack &st, ElemType x)
{	if (st.top == MAX_SIZE-1)	
	return 0;
	else {	
		st.top++;
		st.data[st.top] = x;
		return 1;
	}
}

int PopStack(SqStack &st, ElemType &x)
{	
	if (st.top == -1)
		return 0;
	else {	
		x = st.data[st.top];
		st.top--;
		return 1;
	}
}

int isEmpty(SqStack st)
{	
	if (st.top == -1) 
		return 1;
	else 
		return 0;
}

int OperationJudge(SqStack sqst, char opstr[], int n)
{
	if(!isEmpty(sqst))return 0;
	int i=0;
	ElemType x=0;
	for(;i<n;i++){
		if(opstr[i]=='I'){
			if(!PushStack(sqst,x)) return 0;
		}
		else if(opstr[i]=='O'){
			if(!PopStack(sqst,x)) return 0;
		}
	}
	if(i==n&&isEmpty(sqst))return 1;
	else return 0;
}

int main()
{
	SqStack st;
	InitStack(st);
	char opstr[MAX_SIZE];
	cin >> opstr;
	int islegal = OperationJudge(st, opstr, strlen(opstr));
	cout << islegal << endl;
	return 0;
}

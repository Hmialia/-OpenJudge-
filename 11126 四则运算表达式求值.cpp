#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
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

bool isNumber(char b){
	return (b>='0'&&b<='9')||b=='.';
}

int pri(char b){    
	if(b==')'||b=='(') return 1;    
	if(b=='+'||b=='-') return 2;    
	if(b=='*'||b=='/') return 3;         
}

void Houzhui(char* b){
	
	SqStack st1,st2;
	InitStack(st1);InitStack(st2);
	
	for(int i=0;b[i]!='\0';i++){
		//	cout<<"st1.top="<<st1.data[st1.top]<<", ";
		//	cout<<"扫描到的元素: "<<b[i]<<" ";
		
		if(isNumber(b[i])){
			//		cout<<"数字 ";
			PushStack(st2,b[i]);
			if(b[i+1]=='\0'||!isNumber(b[i+1])){
				//			cout<<"下一个元素是运算符";
				PushStack(st2,'#');
			}
			//		else cout<<"下一个元素不是运算符";
		}
		else if(isEmpty(st1)||b[i]=='('||pri(b[i])>pri(st1.data[st1.top])){
			//		cout<<"直接入S1栈 ";
			PushStack(st1,b[i]);
		}
		else if(b[i]==')'){
			//		cout<<"右括号,依次弹出S1 ";
			
			char x;PopStack(st1,x);
			while(x!='('){
				PushStack(st2,x);
				PopStack(st1,x);
			}
		}
		else if(pri(b[i])<=pri(st1.data[st1.top])){
			//		cout<<"st1.top="<<st1.data[st1.top]<<", ";
			//		cout<<"小于或等于S1栈顶优先级 ";
			while(pri(b[i])<=pri(st1.data[st1.top])&&!isEmpty(st1)&&st1.data[st1.top]!='('){
				char x;PopStack(st1,x);
				PushStack(st2,x);
			}
			PushStack(st1,b[i]);
		}
		//	cout<<endl;
	}
	while(!isEmpty(st1)){
		char x;PopStack(st1,x);
		PushStack(st2,x);		
	}
	while(!isEmpty(st2)){
		char x;PopStack(st2,x);
		PushStack(st1,x);	
	}
	int i;
	for(i=0;!isEmpty(st1);i++){
		PopStack(st1,b[i]);
	}
	b[i]='\0';
}


typedef double ElemType1;
typedef struct {	
	ElemType1 data[MAX_SIZE];
	int top;
} SqStack1;

void InitStack1(SqStack1 &st)
{
	st.top=-1;
}

int PushStack1(SqStack1 &st, ElemType1 x)
{	if (st.top == MAX_SIZE-1)	
	return 0;
	else {	
		//		cout<<"push="<<x<<" ";
		st.top++;
		st.data[st.top] = x;
		return 1;
	}
}

int PopStack1(SqStack1 &st, ElemType1 &x)
{	
	if (st.top == -1)
		return 0;
	else {	
		x = st.data[st.top];
		st.top--;
		return 1;
	}
}

int isEmpty1(SqStack1 st)
{	
	if (st.top == -1) 
		return 1;
	else 
		return 0;
}

double scan(char*b,int& i){
	double sum=0;
	int mul=0;
	
	int i0=i;
	for(;b[i]!='.'&&b[i]!='#'&&b[i]!='\0';i++);
	
	mul=i-i0-1;
	
	i=i0;
	for(;b[i]!='#'&&b[i]!='\0';i++){
		//		cout<<"b[i]="<<b[i]<<" ";
		if(b[i]>='0'&&b[i]<='9'){
			sum+=(b[i]-48)*pow(10,mul);
			mul--;
		}
	}
	return sum;
}

double Cal(char* b){
	SqStack1 st3;
	InitStack1(st3);	
	
	for(int i=0;b[i]!='\0';i++){
		if(isNumber(b[i])){
			double temp=scan(b,i);
			//			cout<<endl<<"scan="<<temp<<" ";
			PushStack1(st3,temp);
		}
		else if(b[i]=='+'){
			//			cout<<endl<<"scan="<<b[i]<<" ";
			double a,b;
			PopStack1(st3,a);
			PopStack1(st3,b);
			PushStack1(st3,a+b);		
		}
		else if(b[i]=='-'){
			//			cout<<endl<<"scan="<<b[i]<<" ";
			double a,b;
			PopStack1(st3,a);
			PopStack1(st3,b);
			PushStack1(st3,b-a);			
		}
		else if(b[i]=='*'){
			//			cout<<endl<<"scan="<<b[i]<<" ";
			double a,b;
			PopStack1(st3,a);
			PopStack1(st3,b);
			PushStack1(st3,a*b);			
		}
		else if(b[i]=='/'){
			//			cout<<endl<<"scan="<<b[i]<<" ";
			double a,b;
			PopStack1(st3,a);
			PopStack1(st3,b);
			PushStack1(st3,b/a);			
		}						
	}
	//	cout<<endl;
	double sum=0;
	while(!isEmpty1(st3)){
		double add;
		PopStack1(st3,add);
		//		cout<<" "<<add;
		sum+=add;
	}
	//	cout<<endl;
	return sum;
}

int main(){
	char b[MAX_SIZE];
	cin>>b;
	
	Houzhui(b);
	
	cout<<fixed<<setprecision(2)<<Cal(b)<<endl;
}

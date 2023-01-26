#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxSize 100				//顺序队的初始分配空间大小

typedef char ElemType;			//假设顺序队中所有元素为int类型

typedef struct QNode {//链队的数据结点类型声明
	ElemType data;
	struct QNode * next;
} QType;

typedef struct qptr {//链队结点的类型声明
	QType * front;
	QType * rear;
} LinkQueue ;

void InitQueue(LinkQueue * &lq) {//初始化队列
	lq = (LinkQueue * )malloc(sizeof(LinkQueue));
	lq->rear = lq->front = NULL;
}

void DestroyQueue(LinkQueue * &lq) {//销毁队列
	QType *pre = lq-> front, * p;
	if (pre != NULL) {
		if (pre == lq->rear)
			free(pre);
		else {
			p = pre-> next;
			while (p != NULL) {
				free(pre);
				pre = p;
				p = p-> next ;
			}
			free(pre);
		}
	}
	free(lq);
}

int EnQueue(LinkQueue * &lq, ElemType x) {//进队
	QType * s;
	s = (QType * )malloc(sizeof(QType));
	s-> data = x;
	s->next = NULL;
	if (lq->front == NULL)
		lq->rear = lq->front = s;
	else {
		lq->rear-> next = s;
		lq->rear = s;
	}
	return 1;
}

int DeQueue(LinkQueue * &lq, ElemType &x) {//出队
	QType * p;
	if (lq-> front == NULL)
		return 0;
	p = lq-> front;
	x = p-> data;
	if (lq-> rear == lq-> front)
		lq-> rear = lq-> front = NULL;
	else
		lq-> front = lq-> front-> next;
	free(p);
	return 1;
}

int GetHead (LinkQueue * lq, ElemType &x) {//取队头元素
	if (lq-> front == NULL)
		return 0;
	x = lq-> front-> data;
	return 1;
}

int QueueEmpty(LinkQueue * lq) {//判断队空
	if (lq-> front == NULL) return 1;
	else return 0 ;
}

int CountNumber(LinkQueue* lq){
	QNode* p=lq->front;
	if(lq-> front == NULL)return 0;
	else if(lq-> front == lq->rear) return 1;
	else{
		int i=1;
		while(p!=lq->rear){
			p=p->next;
			i++;
		}
		return i;
	}
}

int main(){
	//	（1）初始化队列q;
	LinkQueue* lq;
	InitQueue(lq);
	//	（2）判断队列q是否为空；
	if(QueueEmpty(lq)){
		cout<<"yes"<<endl;
	}
	else cout<<"no"<<endl;
	//	（3）依次进队列元素。输入两行数据，第一行是进队字符数据的个数，第二行是具体入队的字符数据。
	int n;cin>>n;
	for(int i=0;i<n;i++){
		char x;cin>>x;
		EnQueue(lq,x);
	}	
	
	//	（4）出队一个元素，并输出该元素；
	char x;
	DeQueue(lq,x);
	cout<<x<<endl;
	
	//	（5）输出队列q的元素个数；
	cout<<CountNumber(lq)<<endl;
	
	//	（6）依次进队列元素。输入两行数据，第一行是进队字符数据的个数，第二行是具体入队的字符数据。
	int m;cin>>m;
	for(int i=0;i<m;i++){
		char x;cin>>x;
		EnQueue(lq,x);
	}	
	//	（7）输出队列q的元素个数；
	cout<<CountNumber(lq)<<endl;
	//	（8）输出出队序列；
	while(!QueueEmpty(lq)){
		char y;
		DeQueue(lq,y);
		cout<<y<<" ";
	}	
	cout<<endl;
	//	（9）释放队列。	
	DestroyQueue(lq);
	return 0;
}

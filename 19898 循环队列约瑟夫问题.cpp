#include <stdio.h>
#define MaxSize 100				//顺序队的初始分配空间大小
typedef int ElemType;			//假设顺序队中所有元素为int类型
typedef struct
{	ElemType data[MaxSize];		//保存队中元素
	int front,rear;				//队头和队尾指针
} SqQueue;


void InitQueue(SqQueue &sq)		//sq为引用型参数
{
	sq.rear=sq.front=0;			//指针初始化
}

void DestroyQueue(SqQueue sq)
{    }

int EnQueue(SqQueue &sq,ElemType x)
{	if ((sq.rear+1) % MaxSize==sq.front)	//队满上溢出
	return 0;
	sq.rear=(sq.rear+1) % MaxSize;			//队尾循环进1
	sq.data[sq.rear]=x;
	return 1;
}

int DeQueue(SqQueue &sq,ElemType &x)		//x为引用型参数
{	if (sq.rear==sq.front)					//队空下溢出
	return 0;
	sq.front=(sq.front+1) % MaxSize;		//队头循环进1
	x=sq.data[sq.front];
	return 1;
}

int QueueEmpty(SqQueue sq)
{	if (sq.rear==sq.front) return 1;
	else return 0;
}

void Josephus(int n,int m)		//用队列求解约瑟夫问题
{
	SqQueue sq;
	InitQueue(sq);
	for(int i=1;i<=n;i++){
		EnQueue(sq,i);
	}
	
	int i=0;int x;
	while(!QueueEmpty(sq)){
		DeQueue(sq,x);
		i++;
		if(i%m!=0){
			EnQueue(sq,x);
		}
		else printf("%d ",x);
	}
}

int main()
{
	int n,m;
	scanf("%d,%d",&n,&m);
	if (n==0 || m==0)
		printf("参数错误,n=%d,m=%d\n",n,m);
	else 
		Josephus(n,m);
}

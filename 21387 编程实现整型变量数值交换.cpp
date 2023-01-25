#include<stdio.h>
void swap(int *pa,int *pb)
{
	int w=*pa;
	*pa=*pb;
	*pb=w;
}
int main() 
{
	int a,b;
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}

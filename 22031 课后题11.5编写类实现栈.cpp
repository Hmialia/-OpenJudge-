#include<iostream>
using namespace std;
struct Node{
	int a;
	Node* next;
};
Node * head=new Node;
Node * s=head;
class Stack{
private:
	Node *p;
public:
	void Put(int item){
		p=new Node;
		p->a=item;
		p->next=s;
		s=p;
	}
	int Get(){
		int temp=s->a;
		p=s->next;
		delete s;
		s=p;
		return temp;
	}
};

int main(){
	Stack sta;
	sta.Put(10);
	sta.Put(12);
	sta.Put(14);
	cout<<sta.Get()<<endl;
	cout<<sta.Get()<<endl;
}

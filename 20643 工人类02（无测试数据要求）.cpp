#include<iostream>
#include<string.h>
using namespace std;
const int N=5;

class Worker{
protected:
	char name[20];
	int level=1;
	float reward=0;
	int ID;
	static int number;
public:
	Worker(){
		number++;
		ID=number;
	}
	Worker(char a[20],int b){
		strcpy(name,a);
		level=b;
		number++;
		ID=number;
	}
	void setName(char a[20]){
		strcpy(name,a);
	}
	void setLevel(int b){
		level=b;
	}
	void setReward(float r){
		reward=r;
	}
	virtual ~Worker(){
		number--;
	}
	virtual float getSalary()=0;
	virtual void infoList()=0;	
};
int Worker::number=0;

class PieceWorker:public Worker{
protected:
	int piece;
public:
	PieceWorker():Worker(){}
	PieceWorker(char a[20],int b,int c):Worker(a,b){
		piece=c;
	}
	void setPiece(int p){
		piece=p;
	}
	virtual ~PieceWorker(){}
	virtual float getSalary(){
		return reward+2000+piece*20+(level-1)*200;
	}
	virtual void infoList(){
		cout<<name<<" ID:"<<ID<<" Level:"<<level<<" Salary:"<<getSalary()<<" Piece="<<piece<<endl;
	}
};

class HourWorker:public Worker{
protected:
	float hour;
public:
	HourWorker():Worker(){}
	HourWorker(char a[20],int b,float c=0):Worker(a,b){
		hour=c;
	}
	void setHour(float h){
		hour=h;
	}
	virtual ~HourWorker(){}
	virtual float getSalary(){
		return reward+2000+hour*50+(level-1)*200;
	}
	virtual void infoList(){
		cout<<name<<" ID:"<<ID<<" Level:"<<level<<" Salary:"<<getSalary()<<" Hour="<<hour<<endl;
	}
};


void setReward(Worker *pWorker, float reward)
{
	pWorker->setReward(reward);
}
int main()
{
	Worker* pWorkerArr[N] = {NULL};
	for(int i=0; i<N; i++)
	{
		char name[20];
		int choice;
		int level=1;
		cin >>name;
		cout<<"PieceWorker(2) or HourWorker(1)?"<<endl;
		cin>> choice;
		switch (choice )
		{
		case 1:
			{	float hour;
				cin >> hour;
				pWorkerArr[i] = (Worker*) new HourWorker(name,level,hour);
			}
			break;
		case 2:
			{	int piece;
				cin >> piece;
				pWorkerArr[i] = (Worker*) new PieceWorker(name,level,piece);
			}
			break;
		}
	}
	
	float totalSalary = 0.0f;
	for( int i=0;i<N;i++)
	{
		if (pWorkerArr[i] != NULL)
		{
			totalSalary += pWorkerArr[i]->getSalary();
		}
	}
	cout <<"totalSalary="<< totalSalary << endl;
	
	for (int i = 0; i<N; i++)
	{
		if (pWorkerArr[i] != NULL)  delete pWorkerArr[i];
	}
	return 0;
}

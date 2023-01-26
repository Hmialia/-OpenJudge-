#include <iostream> 
using namespace std;
#include <string.h> 

const int CARNO_DIGIS=8; 
const int ACCESS_TIMES=100;
class CarAccess{
	
protected:
	char carno[CARNO_DIGIS+1];
	float fee;
	int intime;
	public:	
	static int carCount;
	CarAccess(char cao[CARNO_DIGIS+1],int curtime){
		strcpy(carno,cao);
		intime=curtime;
		CarAccess::carCount++;	
	}
	virtual ~CarAccess(){
		CarAccess::carCount--;	
	}
	virtual void Print(){
		cout<<carno<<" "<<intime<<endl;
	}
	virtual float GetFee(int)=0;
	char* GetCarno(){
		return carno;
	}
};
int CarAccess::carCount=0;

class StaffCar:public CarAccess{
public:
	static int carCount;
	virtual ~StaffCar(){
		StaffCar::carCount--;
	}
	StaffCar(char cao[CARNO_DIGIS+1],int cur):CarAccess(cao,cur){
		StaffCar::carCount++;
	}
	virtual void Print(){
		cout<<carno<<" "<<intime<<" S"<<endl;
	}
	virtual float GetFee(int outtime){
		return 0;
	}
};
int StaffCar::carCount=0;

class VisitCar:public CarAccess{
public:
	static int carCount;
	virtual ~VisitCar(){
		VisitCar::carCount--;
	}
	VisitCar(char cao[CARNO_DIGIS+1],int cur):CarAccess(cao,cur){
		VisitCar::carCount++;
	}
	virtual void Print(){
		cout<<carno<<" "<<intime<<" V"<<endl;
	}
	virtual float GetFee(int outtime){
		float fee=(outtime-intime)*8;
		return fee;
	}
};
int VisitCar::carCount=0;

void Depart( CarAccess *p ,int time)
{
	if(p!=NULL)
	{
		cout<<p->GetCarno()<<" "<<p->GetFee(time)<<endl;
		delete p;
	}
} 
int main() 
{  
	CarAccess* cars[ACCESS_TIMES] = {NULL};  
	int n;	cin>>n;
	
	for(int i=0;i < n; i++)  
	{   
		char carno[CARNO_DIGIS+1];  			
		cin >> carno;    
		int InOut;   	cin >> InOut;   
		int curtime;	cin>>curtime;		
		
		if ( InOut == 1 ) //车辆驶入   
		{    
			char type; 	cin >> type;    
			if ( type == 'S' )     
				cars[i] = new StaffCar(carno,curtime);    
			else if (type == 'V')     
				cars[i] = new VisitCar(carno,curtime); 
			else 
				i--; 
		}   
		else if( InOut == 2 )  //车辆驶出 
		{ 
			if ( i == 0 ) break;    
			bool flag = false;
			for (int j = i-1;j >= 0; j--)    
			{     
				if ( cars[j] == NULL ) continue;     
				if ( strcmp(cars[j]->GetCarno(), carno)  == 0 )     
				{      
					Depart(cars[j],curtime);
					cars[j] = NULL;
					flag = true;
					break;     
				}     
			}
			if(!flag)
				cout << "err" << endl;      	
		} 
		else
			break;    
	}  
	cout << CarAccess::carCount <<" "<< StaffCar::carCount <<" "<< VisitCar::carCount << endl; 
	
	for (int k = 0; k < n; k++)   
		if  ( cars[k] != NULL ) 
	{
		cars[k]->Print(); 
		delete cars[k]; 
	}	
	return 0;
}

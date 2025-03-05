#include <iostream>
#include <cstdlib>
using namespace std;
class queue{
	int *q;
	int front;
	int rear;
	int len;
	public:
	queue(int x){
		front=-1;
		rear=-1;
		len=x;
		q=(int*)malloc(len*sizeof(int));
	}
	enqueue(int element){
		if((rear+1)%len==front){
			cout<<"full"<<endl;
		}
		else if(rear==-1 &&front==-1){
			front=rear=0;
			q[rear]=element;
		}
		else{
			rear=(rear+1)%len;
			q[rear]=element;
		}
	}
	dequeue(){
		if(rear==-1 && front==-1){
			cout<<"empty";
		}
		else if(rear==front){
			rear=front=-1;
		}
		else{
			front=(front+1)%len;
		}
	}
	display(){
		int i=front;
		if(rear==-1 && front==-1){
			cout<<"empty";
		}
		else{
			while(i!=rear){
				cout<<q[i];
				i=(i+1)%len;
			}
		}	
	}	
};
int main(){
	int len,i,n,x;
	cout<<"length:";
	cin>>len;
	queue q(len);
	i=0;
	cout<<"elements:"<<endl;
	while(i<len){
		cin>>x;
		q.enqueue(x);
		i++;
	}
//	q.dequeue();
	//q.enqueue(9);
	q.display();
}	

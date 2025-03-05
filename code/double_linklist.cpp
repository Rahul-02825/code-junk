#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node{
        int data;
        node *fwd;
        node *bwd;
}node;
void insert(node *&start,int element){
        node*ptr=start;
        while(ptr->fwd!='\0'){
                ptr=ptr->fwd;
        }
        if(ptr==start && ptr->data==0){
                ptr->data=element;
        }
        else{
                node *newnode=new node;
                newnode->fwd='\0';
                newnode->bwd=ptr;
                newnode->data=element;
                ptr->fwd=newnode;
        }
}
void display(node *&start){
	node *ptr=start;
	while(ptr!='\0'){
		cout<<ptr->data<<endl;
		ptr=ptr->fwd;
	}
}
void reverse(node *&start){
	node *ptr=start;
	node *temp;
	while(ptr->fwd!='\0'){
		ptr=ptr->fwd;
	}
	temp=ptr;
	while(temp!='\0'){
		cout<<temp->data<<endl;
		temp=temp->bwd;
	}
}
void interchange(node *&start,int elt){
	node*ptr=start;
	node *p1;
	int count=1;
	while(ptr->data!=elt){
		ptr=ptr->fwd;
	}
	/*ptr->fwd->bwd=ptr->bwd;
	ptr->bwd=ptr->fwd;
	ptr->fwd=ptr->bwd->fwd;
	ptr->bwd->fwd=ptr;
	ptr->bwd->bwd->fwd=ptr->bwd;
	ptr->fwd->bwd=ptr;	*/
	p1=ptr->fwd->fwd;
	ptr->bwd->fwd=ptr->fwd;
	ptr->fwd->bwd=ptr->bwd;
	ptr->fwd->fwd=ptr;
	ptr->bwd=ptr->fwd;
	ptr->fwd=p1;	
}
int main(){
	int n,x,i,y;
	node *start=new node;
	start->fwd='\0';
	start->bwd='\0';
	start->data=0;
	cout<<"Give the number of number of elements:";
	cin>>n;
	cout<<"Give the element:";
	i=0;
	while(i<n){
		cin>>x;
		insert(start,x);
		i++;
	}
	cout<<"y:";
	cin>>y;
	interchange(start,y);
	display(start);
}

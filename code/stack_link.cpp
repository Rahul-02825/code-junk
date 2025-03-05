#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node{
        int data;
        node *link;
}node;
int stackempty(node *&start){
	if(start=='\0'){
		return 1;
	}
	else{
		return 0;
	}	
}
int stackfull(node *&start,int n){
	int count;
	node *ptr=start;
	while(ptr!='\0'){
		count++;
		ptr=ptr->link;
	}
	if(count==n){
		return 1;
	}
	else{
		return 0;
	}
}
void push(node *&start,int element,int n)
{
	if(stackfull(start,n)==1){
		cout<<"stack full";
	}
	else{
		node*ptr=start;
        while(ptr->link!='\0'){
                ptr=ptr->link;
        }
        if(ptr==start && ptr->data==0){
                ptr->data=element;
        }
        else{
                node *newnode=new node;
                newnode->link='\0';
                newnode->data=element;
                ptr->link=newnode;
        }	 
	}
}
void pop(node *&start){
	node *ptr=start;
	node *p;
	if(stackempty(start)==1){
		cout<<"stack is empty";
	}
	else{
		while(ptr->link!='\0'){
			p=ptr;
			ptr=ptr->link;
		}
		free(ptr);
		ptr=p;
		ptr->link='\0';
		
	}
}
void display(node *&start){
	node *ptr=start;
	while(ptr!='\0'){
		cout<<ptr->data<<endl;
		ptr=ptr->link;
	}
}
int main()
{
	int n,x,i;
	node *start=new node;
	start->link='\0';
	start->data=0;
	cout<<"Give the number of number of elements:";
	cin>>n;
	cout<<"Give the element:";
	i=0;
	while(i<n){
		cin>>x;
		push(start,x,n);
		i++;
	}
	pop(start);
	push(start,6,n);
	display(start);
}

#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node{
        int data;
        node *link;
}node;
void insert(node *&start,int element){
	   node *ptr;
       node *newnode=new node;
       newnode->data=element;
       newnode->link=ptr;
       ptr=start;
       while(ptr->link!=start){
       	ptr=ptr->link;
	   }
	   ptr->link=newnode;
}
void display(node *&start){
	node *ptr=start;
	while(ptr!='\0'){
		cout<<ptr->data<<endl;
		ptr=ptr->link;
	}
}
void delete_last(node *&start){
	node *ptr=start;
	node *p1;
	if(start=='\0'){
		cout<<"empty";
	}
	else if(start->link=='\0'){
		start='\0';
		free(start);		
	}
	else{
		while(ptr->link!='\0'){
			p1=ptr;
			ptr=ptr->link;
		}
		p1->link='\0';
		free(ptr);
	}
}

int main(){
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
		insert(start,x);
		i++;
	}
}

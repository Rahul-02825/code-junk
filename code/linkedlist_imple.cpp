#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node{
        int data;
        node *link;
}node;
typedef struct node1{
	int data1;
	node1 *link1;
}node1;
void insert(node *&start,int element){
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
void insert1(node1 *&start1,int element1){
        node1 *ptr1=start1;
        while(ptr1->link1!='\0'){
                ptr1=ptr1->link1;
        }
        if(ptr1==start1 && ptr1->data1==0){
                ptr1->data1=element1;
        }
        else{
                node1 *newnode1=new node1;
                newnode1->link1='\0';
                newnode1->data1=element1;
                ptr1->link1=newnode1;
        }
}
void display(node *&start){
	node *ptr=start;
	while(ptr!='\0'){
		cout<<ptr->data<<endl;
		ptr=ptr->link;
	}
}
void display1(node1 *&start1){
	node1 *ptr1=start1;
	while(ptr1!='\0'){
		cout<<ptr1->data1<<endl;
		ptr1=ptr1->link1;
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
void remdup(node *&start1){
	node *ptr=start;
	while(ptr->link!='\0'){
		if(ptr->data==ptr->link->data){
			ptr->link=ptr->link->link;
			free(ptr->link);
		}
	}
}
void merge(node *&start,node1 *&start1){
	node *ptr=start;
	node1 *ptr1=start1;
	while(ptr->link!='\0'){
		ptr=ptr->link;
	}
	ptr->link=ptr1;
}
int main(){
	int n,x,i,j,y;
	node *start=new node;
	start->link='\0';
	start->data=0;
	node1 *start1=new node1;
	start1->link1='\0';
	start1->data1=0;
	cout<<"Give the number of number of elements:";
	cin>>n;
	cout<<"Give the element:"<<endl;
	i=0;
	while(i<n){
		cin>>x;
		insert(start,x);
		i++;
	}
	cout<<"Give the element:"<<endl;
	j=0;
	while(j<n){
		cin>>y;
		insert1(start1,y);
		j++;
	}
	cout<<"1st linkedlist:"<<endl;		
	display(start);
	cout<<"2nd linkedlist:"<<endl;
	display1(start1);
}

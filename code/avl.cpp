#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node{
	int key;
	node * left;
	node * right;
	int height;
}node;
class AVL{
	public:
		node * root=NULL;
		AVL(int data){
			root=new node;
			root->left=NULL;
			root->right=NULL;
			//root->height=1;iou
			root->key=data;
		}
		int max(int a,int b){
			return (a>b)?a:b;
		}
		int height(node* N){
			if(N==NULL)
				return 0;
			return(N->height);
		}
		int get_balance(node *N){
			if(N==NULL)
				return 0;
				
				
			return height(N->left)-height(N->right);
		}
		node * right_rotate(node * x){
			node *y=x->left;
			node *T2=y->right;
			//rotate
			y->right=x;
			x->left=T2;
			//update heights
			x->height=1+max(height(x->left),height(x->right));
			y->height=1+max(height(y->left),height(y->right));
			return  y;
		}
		node * left_rotate(node * x){
			node *y=x->right;
			node *T2=y->left;
			//rotate
			y->left=x;
			x->right=T2;
			//update heights
			x->height=1+max(height(x->left),height(x->right));
			y->height=1+max(height(y->left),height(y->right));
			return  y;
		}

		node * insert(node * no,int key){
			if(no==NULL){
				no=new node;
				no->key=key;
				no->height=1;
				no->left=NULL;
				no->right=NULL;
				return no;				
			}
			//bst insertion
			if(key<no->key){
				no->left=insert(no->left,key);
			}
			else if(key>no->key){
				no->right=insert(no->right,key);
			}   
			else{
				return no;
			}
			no->height=1+max(height(no->left),height(no->right));
			int balance=get_balance(no);
			//ll case
			if(balance>1 && key<no->left->key){
				return right_rotate(no);				
			}
			//lR CASE
			if(balance>1 && key>no->left->key){
				no->left=left_rotate(no->left);
				return right_rotate(no);
			}
			//RR case
			if(balance<-1 && key>no->right->key ){
				return left_rotate(no); 
			}
			//Rl case
			if(balance<-1 && key<no->right->key){
				no->right=right_rotate(no->left);
				return left_rotate(no);
			}
			return no;
		}
		void preorder(node *root)
        {
            if(root != NULL)
            {
            	cout << root->key << " ";
                preorder(root->left);
                preorder(root->right);
                    
        	}
    	}
             node * min_node(node * x){
                        node * current=x;
                        while(current->left!=NULL){
                                current=current->left;
                        }
                        return current;
                }
                node * deletion(node * root,int key){
                        if(root==NULL){
                                return root;
                        }
                        if(key<root->key){
                                root->left=deletion(root->left,key);
                        }
                        else if(key>root->key){
                                root->right=deletion(root->right,key);
                        }
                        else{
                                //node with one or no child
                                if(root->left==NULL||root->right==NULL){
                                        node* temp=root->left?root->left:root->right;
                                        //node with no child
                                        if(temp==NULL){
                                                temp=root;
                                                root=NULL;
                                            }
                                        else{
                                                //one chile case
                                                *root=*temp;
                                        }
                                        free(temp);
                                }
                                else{
                                        //if root  has two children
                                        node * temp=min_node(root->right);
                                        root->key=temp->key;
                                        //delete the inorder
                                        root->right=deletion(root->right,temp->key);
                                }
                        }
                        if(root==NULL){
                                return root;
                            }
                        
                        root->height=max(height(root->right),height(root->left))+1;
                        int balance=get_balance(root);
						//BALANCING
						//LL CASE:
						if(balance>1 && get_balance(root->left)>=0){
							return right_rotate(root);
						}
						//LR case
						if(balance >1 && get_balance(root->left)<0){
							root->left=left_rotate(root->left);
							return right_rotate(root);
						}
						//RR case
						if(balance<-1 && get_balance(root->right)<=0){
							return left_rotate(root);
						}
						//Rl case
						if(balance <-1 && get_balance(root->right)>0){
							root->right=right_rotate(root->right);
							return left_rotate(root);
						}
						return root;
			}
						
};
int main(){
	AVL a(21);
        a.root = a.insert(a.root,26);
        a.root = a.insert(a.root, 30);
        a.root = a.insert(a.root, 9);
        a.root = a.insert(a.root, 4);
        a.root = a.insert(a.root, 14);
        a.root = a.insert(a.root, 28);
        a.root = a.insert(a.root, 18);
        a.root = a.insert(a.root, 15);
        a.root = a.insert(a.root, 10);
        a.root = a.insert(a.root, 2);
        // a.root = a.insert(a.root, 28);        
        //a.root=a.deletion(a.root,10);

        cout << "Preorder traversal of the "
                        "constructed AVL tree is \n";
        a.preorder(a.root);

        return 0;
}

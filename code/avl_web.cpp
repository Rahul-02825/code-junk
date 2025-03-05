#include<iostream>
using namespace std;

typedef struct Node {
    int key;
    Node * left;
    Node * right;
    int height;
}Node;

class AVL
{
        private:
                Node *root;
        public:
                AVL()
                {
                        root = new Node;
                        cout<<"\nEnter the Value : ";
                        cin>>root->key;
                        root->left=NULL;
                        root->right=NULL;
                        cout<<root->key;
                }

                int height(Node * N)
                {
                        if (N == NULL)
                                return 0;
                        return N -> height;
                }

                int max(int a, int b)
                {
                        return (a > b) ? a : b;
                }

                Node * leftRotate(Node * y)
                {
                        Node * x = y -> left;
                        Node * T2 = x -> right;
                        x -> right = y;
                        y -> left = T2;
                        y -> height = max(height(y -> left), height(y -> right)) + 1;
                        x -> height = max(height(x -> left), height(x -> right)) + 1;
                        return x;
                }

                Node * rightRotate(Node * x)
                {
                        Node * y = x -> right;
                        Node * T2 = y -> left;
                        y -> left = x;
                        x -> right = T2;
                        x -> height = max(height(x -> left), height(x -> right)) + 1;
                        y -> height = max(height(y -> left), height(y -> right)) + 1;
                        return y;
                }

                int getBalance(Node * N)
                {
                }

                void insert()
                {
                        int i=0;
                        cout<<"\nEnter the Value : ";
                        cin>>i;
                        root = ins(root,i);
                }

                Node * ins(Node * node, int key)
                {
                        if (node == NULL)
                        {
                                node = new Node();
                                node -> key = key;
                                node -> left = NULL;
                                node -> right = NULL;
                                node -> height = 1;
                                return node;
                        }
                        if (key < node -> key)
                                node -> left = ins(node -> left, key);
                        else if (key > node -> key)
                                node -> right = ins(node -> right, key);
                        else
                                return node;
                        node -> height = 1 + max(height(node -> left),height(node -> right));
                        int balance = getBalance(node);
                        if (balance > 1 && key < node -> left -> key)
                                return leftRotate(node);
                        if (balance < -1 && key > node -> right -> key)
                                return rightRotate(node);
                        if (balance > 1 && key > node -> left -> key)
                        {
                                node -> left = rightRotate(node -> left);
                                return leftRotate(node);
                        }
                        if (balance < -1 && key < node -> right -> key)
                        {
                                node -> right = leftRotate(node -> right);
                                return rightRotate(node);
                        }
                        return node;
                }

                Node * minValueNode(Node * node)
                {
                        Node * current = node;
                        while (current -> left != NULL)
                                current = current -> left;
                        return current;
                }

                void del()
                {
                        int i=0;
                        cout<<"\nEnter the Value : ";
                        cin>>i;
                        root = deleteNode(root,i);
                }

                Node * deleteNode(Node * root, int key)
                {
                        if (root == NULL)
                                return root;
                        if (key < root -> key)
                                root -> left = deleteNode(root -> left, key);
                        else if (key > root -> key)
                                root -> right = deleteNode(root -> right, key);
                        else
                        {
                                if ((root -> left == NULL) ||(root -> right == NULL))
                                {
                                        Node * temp = root -> left ? root -> left : root -> right;
                                        if (temp == NULL)
                                        {
                                                temp = root;
                                                root = NULL;
                                        }
                                        else
                                                *root = * temp;
                                        delete temp;
                                }
                                else
                                {
                                        Node * temp = minValueNode(root -> right);
                                        root -> key = temp -> key;
                                        root -> right = deleteNode(root -> right,temp -> key);
                                }
                        }
                        if (root == NULL)
                                return root;
                        root -> height = 1 + max(height(root -> left),height(root -> right));
                        int balance = getBalance(root);
                        if (balance > 1 && getBalance(root -> left) >= 0)
                                return leftRotate(root);
                        if (balance > 1 && getBalance(root -> left) < 0)
                        {
                                root -> left = rightRotate(root -> left);
                                return leftRotate(root);
                        }
                        if (balance < -1 && getBalance(root -> right) <= 0)
                                return rightRotate(root);
                        if (balance < -1 && getBalance(root -> right) > 0)
                        {
                                root -> right = leftRotate(root -> right);
                                return rightRotate(root);
                        }
                        return root;
                }

                void pre()
                {
                        preOrder(root);
                }

                void preOrder(Node * root)
                {
                        if (root != NULL)
                        {
                                cout << root -> key << " ";
                                preOrder(root -> left);
                                preOrder(root -> right);
                        }
                }
};

int main()
{
        AVL a;
        a.insert();
        a.insert();
        cout <<"\nPreorder traversal of the constructed AVL tree is : ";
        a.pre();
        a.del();
        cout <<"\nPreorder traversal after deletion is : ";
        a.pre();
        cout<<endl;
        

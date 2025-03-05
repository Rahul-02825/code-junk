#include<iostream>
#include<cstdlib>
#include<cstring>
#include <fstream>
using namespace std;
typedef struct node
{
  char* mean;
  node** child;
}node;


class Tries{
    private:
        node* root;
    public:
        Tries(){
            root=new node;
            root->mean=NULL;
            root->child=(node**)calloc(26,sizeof(node*));
        }
        int letter(char);
        int insert_(char*,char*);
        int meaning(char* );
};

int Tries::letter(char x){
    switch(x){
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;
        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;
        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;
        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;
        case 'z':
            return 25;
        default:
            return -1;
    }
}
int Tries::insert_(char* word,char* m){
    int i,le;
    node* ptr=root;
    for(i=0;i<strlen(word);i++){

        le=letter(word[i]);
        if(ptr->child[le]!=NULL){
            ptr=ptr->child[le];
        }else{
            node* newnode=new node;
            newnode->mean=NULL;
            newnode->child=(node**)calloc(26,sizeof(node*));
            ptr->child[le]=newnode;
            ptr=newnode;
        }
    }
    ptr->mean=m;
    return 1;
}
int Tries::meaning(char* word){
    int i,le;
    node* ptr=root;
    for(i=0;i<strlen(word);i++){
        le=letter(word[i]);
        if(ptr->child[le]!=NULL){
            ptr=ptr->child[le];
        }else{
            return 0;
        }
    }
    cout<<"\n\n\t\t\t\t"<<ptr->mean;
    return 1;

}

int main(){
    Tries a;
    /*a.insert_("hello","Greetings");
    a.meaning("hello");*/
    fstream file;
	file.open("dict.txt",fstream::in);
	string find;
	string mean;
	cout<<"Give the meaning to be found:"<<endl;
	cin>>find; 
	if(file.is_open()){
		string word;
		string meaning;
		bool found=false;
		while(!file.eof()){
			file>>word>>meaning;
			if(word==find){
				mean=meaning;
				cout<<"THe corresponding meaning is:"<<meaning<<endl;
				found=true;
				break;
			}
		} 
		if(found==false){
			cout<<"word not found in the dictionary"<<endl;
		}
	}
	else{
		cout<<"error";
	}
	// variables to be passed
	//cout<<find<<endl;
	//cout<<mean<<endl;
	//a.insert_(find,mean);
	//a.meaning(find);
    
}

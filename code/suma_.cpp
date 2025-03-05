#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(){
	fstream file;
	file.open("try.txt",fstream::in);
	while(1){
	}
	string find;
	cout<<"Give the meaning to be found:"<<endl;
	cin>>find; 
	if(file.is_open()){
		string word;
		string meaning;
		bool found=false;
		while(!file.eof()){
			file>>word>>meaning;
			if(word==find){
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
}

#include<iostream>
using namespace std;
class a{
	private:
		int x;
	public:
		void get(){
			cout<<"x:";
			cin>>x;
		}
		int give(){
			return x;
		}
		
};
class b{
	private:
		int y;
	public:
		void get(){
			cout<<"y:";
			cin>>y;
		}
		int give(){
			return y;
		}
};
class c:private a,private b{
	private:
		int z;
	public:
		void get(){
			a::get();
			b::get();
			cout<<"z:";
			cin>>z;
		}
		 void sumc(){
		 	int k=a::give();
		 	int l=b::give();
		 	int add=l+k+z;
		 	cout<<z;
		 }
		
};
int main(){
	c obj;
	obj.get();
	obj.sumc();
}

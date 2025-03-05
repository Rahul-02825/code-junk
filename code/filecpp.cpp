#include<iostream>
using namespace std;
  
class base {
public:
    virtual void print(int x)
    {
        cout << "print base class\n";
    }
  
    void show()
    {
        cout << "show base class\n";
    }
};
  
class derived : public base {
public:
    void print(int x)
    {
        cout << "print derived class\n";
    }
  
    void show()
    {
        cout << "show derived class\n";
    }
};
  
int main()
{
	int k;
    base *bptr;
    derived d;
    bptr = &d;
  
    // Virtual function, binded at runtime
    bptr->print(k);
  
    // Non-virtual function, binded at compile time
    bptr->show();
    
    return 0;
}

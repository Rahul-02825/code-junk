#include <iostream>
using namespace std;
class RECTANGLE{
        int l,b;
        public:
                RECTANGLE() : l(0),b(0) {}
                RECTANGLE(int x , int y) :l(x),b(y) {}
                friend RECTANGLE operator+(RECTANGLE,RECTANGLE);
                RECTANGLE operator-(RECTANGLE);
                RECTANGLE operator*(RECTANGLE);
                RECTANGLE operator=(RECTANGLE);
                bool operator==(RECTANGLE);
                friend ostream& operator<< (ostream& , RECTANGLE);
                friend istream& operator>>(istream&, RECTANGLE&);
};


RECTANGLE operator+(RECTANGLE t,RECTANGLE other){
        return RECTANGLE(t.l+other.l , t.b+other.b);
}

RECTANGLE RECTANGLE::operator-(RECTANGLE other){
        return RECTANGLE(this->l-other.l , this->b-other.b);
}

RECTANGLE RECTANGLE::operator*(RECTANGLE other){
        return RECTANGLE(this->l*other.l , this->b*other.b);

}

RECTANGLE RECTANGLE::operator=(RECTANGLE other){
        this->l = other.l;
        this->b = other.b;
        return *this;
}

bool RECTANGLE::operator==(RECTANGLE other){
        return (this->l==other.l && this->b == other.b) ;
}

ostream& operator<< (ostream& c, RECTANGLE r){
        c<< "Length = "<<r.l<< " Breadth = "<<r.b<<endl;
        return c;
}

istream& operator>>(istream& c, RECTANGLE& r){
        cout<<"Enter length :";
        c>>r.l;
        cout<<"Enter breadth :";
        cin>>r.b;
        return c;
}

int main(){
        RECTANGLE a(10,20),b(30,40),c;
        cin>>c;
        cout<<"c+a"<<c+a;
        cout<<"a "<<a<<"b "<<b<<"a+b "<<a+b<<"a-b "<<a-b<<"a*b "<<a*b<<"a==b "<< (a==b)<<endl;
        cout<<c;
}

#include<iostream>
using namespace std;

class Crc{
        public:
                Crc(){
                }
                void division(int*p,int*a,int* b,int n,int m){
                        int k=0;
                        for(int i=0;i<n;i++){
                                b[i]=a[i];
                                k++;
                        }
                        for(int i=0;i<n;i++){
                                cout<<b[i]<<" ";
                        }
                        cout<<"\n";
                        for(int i=n;i<m+n;){
                                if(b[0]==1){
                                        for(int j=0;j<n;j++){
                                                if((p[j]==1 && b[j]==1) || (p[j]                                                                                                             ==0 && b[j]==0))
                                                        b[j]=0;
                                                else
                                                b[j]=1;
                                        }
                                }
                                for(int i=0;i<n;i++){
                                        cout<<b[i]<<" ";
                                }
                                cout<<"\n";
                                if(i!=m+n-1){
                                        for(int j=1;j<n;j++)
                                                b[j-1]=b[j];
                                        b[n-1]=a[i];
                                }
                                i++;
                        }
                        /*for(int i=0;i<n;i++){
                                cout<<b[i]<<" ";
                        }*/
                }
};

class Parity{
        int n;
        public:
                Parity(int x){
                        n=x;
                }
                void input(int *a){
                        for(int i=0;i<n;i++){
                                cin>>a[i];
                        }
                }
                void check(int s,int *a){
                        //cout<<"IN\n";
                        int count=0;
                        for(int i=0;i<n;i++){
                                if(a[i]==1){
                                        count++;
                                }
                        }
                        if(s==1){
                                if(count%2!=0){
                                        a[n]=0;
                                }else{
                                        a[n]=1;
                                }
                        }else if(s==0){
                                if(count%2!=0){
                                        a[n]=1;
                                }else{
                                        a[n]=0;
                                }
                        }else{
                                cout<<"3";
                        }
                }
                int D2colcheck(int** a,int m,int *c){
                        for(int i=0;i<n;i++){
                                c[i]=a[0][i];
                        }
                        for(int i=1;i<m;i++){
                                for(int j=0;j<n;j++){
                                        if(c[j]==1 && a[i][j]==0){
                                                c[j]=0;
                                        }else{
                                                c[j]=1;
                                        }
                                }
                        }
                }
                void disp(int *a){
                        for(int i=0;i<=n;i++){
                                cout<<a[i]<<" ";
                        }
                }
};

class Checksum{
        public:
                Checksum(){
                }
                void check(int **a,int *b,int m,int n){
                        int c=0;
                        for(int i=0;i<n;i++){
                                b[i]=a[0][i];
                        }
                        for(int i=1;i<m;i++){
                                for(int j=n-1;j>=0;j--){
                                        if(a[i][j]==1 && b[j]==1 && c==1){
                                                b[j]=1;
                                                c=1;
                                        }else if((a[i][j]==1 && b[j]==1) ||(a[i][j]==1 && c==1)||(c==1 && b[j]==1)){
                                                b[j]=0;
                                                c=1;
                                        }else{
                                                b[j]=b[j]+a[i][j];
                                        }
                                }
                                if(c==1){
                                        for(int j=n-1;j>=0;j--){
                                                if(b[j]==0){
                                                        b[j]=1;
                                                        break;
                                                }else{
                                                        b[j]=0;
                                                }
                                        }
                                }
                                c=0;
                        }
                }
                void comp(int *b,int n){
                        for(int i=0;i<n;i++){
                                if(b[i]==0){
                                        b[i]=1;
                                }else{
                                        b[i]=0;
                                }
                        }
                }
                void dispq(int **a,int m,int n){
                        for(int i=0;i<m;i++){
                                for(int j=0;j<n;j++){
                                        cout<<a[i][j];
                                }
                                cout<<" ";
                        }
                }
                void disp(int *b,int n){
                         for(int i=0;i<n;i++){
                                cout<<b[i];
                        }
                        cout<<"\n";
                }
};

int main(){
        int x;
        cout<<"1) For Parity \n2) For Crc \n3) For Checksum \nEnter Your Choice : ";
        cin>>x;
        switch(x){
                case 1:{
                        int n,m;
                        int *c,*r,*d;
                        int s,h;
                        cout<<"Enter 1D(1) or 2D(2) : ";
                        cin>>h;
                        cout<<"Enter n bits : ";
                        cin>>n;
                        c=new int[n+1];
                        r=new int[n+1];
                        d=new int[n+1];
                        Parity p(n);
                        cout<<"Enter no of sections: ";
                        cin>>m;
                        int **a;
                        a = new int*[m];
                        for(int i = 0; i <m; i++)
                                a[i]=new int[n];
                        cout<<"Enter odd(1) or even(0) : ";
                        cin>>s;
                        for(int i=0;i<m;i++){
                                cout<<"FOR "<<i+1<<":-\n";
                                p.input(a[i]);
                                p.check(s,a[i]);
                        }
                        for(int i=0;i<m;i++){
                                p.disp(a[i]);
                                cout<<"\n";
                        }
                        p.D2colcheck(a,m,c);
                        p.check(s,c);
                        if ( h == 2 )
                            p.disp(c);
                        for(int i=0;i<=n;i++){
                                d[i]=c[i];
                        }
                        cout<<"\n";
                        cout<<"Enter reciever data:- \n";
                        for(int i=0;i<m;i++){
                                cout<<"FOR "<<i+1<<":-\n";
                                p.input(a[i]);
                                p.check(s,a[i]);
                        }
                        for(int i=0;i<m;i++){
                                p.disp(a[i]);
                                cout<<"\n";
                        }
                        p.D2colcheck(a,m,c);
                        p.check(s,c);
                        p.disp(c);
                        cout<<"\n";
                        for(int i=0;i<=n;i++){
                                if(d[i]!=c[i]){
                                        cout<<"Error detected";
                                        break;
                                }if(i==n){
                                        cout<<"No Error";
                                }
                        }
                        break;
                }
                case 2:{
                    int n,m,k=0;
                        int *p,*a,*b;
                        cout<<"Enter Key( power ) : ";
                        cin>>n;
                        p=new int(n);
                        b=new int(n);
                        for(int i=n-1;i>=0;i--){
                                cin>>p[k];
                                k++;
                        }
                        a=new int(m+n);
                        cout<<"Enter no of bits in the data: ";
                        cin>>m;
                        for(int i=0;i<m;i++){
                                cin>>a[i];
                        }
                        for(int i=m;i<m+n;i++){
                                a[i]=0;
                        }
                        Crc c;
                        c.division(p,a,b,n,m);
                        for(int i=0;i<n;i++){
                                cout<<b[i]<<" ";
                        }
                        cout<<"\n";
                        for(int i=1,k=m;i<n;k++,i++){
                                if(a[k]!=1)
                                        a[k]=b[i];
                        }
                        for(int i=0;i<m+n-1;i++){
                                cout<<a[i];
                        }
                        cout<<"\n";
                        cout<<"Reciever data: \n";
                        for(int i=0;i<m+n;i++){
                                cin>>a[i];
                        }
                        c.division(p,a,b,n,m);
                        for(int i=0;i<n;i++){
                                if(b[i]!=0){
                                        cout<<"Error detected";
                                        break;
                                }if(i==n-1){
                                        cout<<"No Error detected";
                                }
                        }
                        break;
                }


                case 3:{
                        int**a;
                        int *b,*d;
                        int m,n;
                        cout<<"Enter no of bits: ";
                        cin>>n;
                        cout<<"Enter no of sections: ";
                        cin>>m;
                        b=new int[n];
                        d=new int[n];
                        a=new int*[m];
                        for(int i=0;i<m;i++){
                                a[i]=new int[n];
                        }
                        for(int i=0;i<m;i++){
                                for(int j=0;j<n;j++){
                                        cin>>a[i][j];
                                }
                        }
                        Checksum c;
                        c.check(a,b,m,n);
                        c.comp(b,n);
                        c.dispq(a,m,n);
                        c.disp(b,n);
                        for(int i=0;i<n;i++){
                                d[i]=b[i];
                        }
                        cout<<"Reciever:\n";
                        /*cout<<"Enter no of bits:- ";
                        cin>>n;
                        cout<<"Enter no of sections:- ";
                        cin>>m;*/
                        for(int i=0;i<m;i++){
                                for(int j=0;j<n;j++){
                                        cin>>a[i][j];
                                }
                        }
                        c.check(a,b,m,n);
                        c.dispq(a,m,n);
                        c.disp(b,n);
                        for(int i=0;i<n;i++){
                                if((b[i]==0 && d[i]==0)||(b[i]==1 && d[i]==1)){
                                        cout<<"\nError detected";
                                        break;
                                }if(i==n-1){
                                        cout<<"\nNo Error detected";
                                }
                        }
                }
        }
}


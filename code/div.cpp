#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int divisor;
    int dividend;
    cout<<"Give the dividend:";
    cin>>dividend;
    cout<<"GIve the divisor:";
    cin>>divisor;
    if((divisor>pow(2,-31) || divisor<pow(2,31)) && (dividend>pow(2,-31) ||dividend<pow(2,31))){
        if(divisor==0 || dividend==0){
            cout<<"invalid";
        }
        else{
        	long long int diff;
        	long long int i=0;
        	if(divisor<0 && dividend<0){
        		divisor=abs(divisor);
        		dividend=abs(dividend);
        		if(divisor>dividend){
        			cout<<"ans:"<<0;
				}
            	else{
            		while(1){
                	diff=dividend-divisor;
                	dividend=diff;
                	i++;
                	if(diff<divisor){
                    break;
                	}
            	}
            	cout<<"ans:"<<i;
				}
			}
			else if(divisor<0 || dividend<0){
				divisor=abs(divisor);
        		dividend=abs(dividend);
            	while(1){
                	diff=dividend-divisor;
                	dividend=diff;
                	i++;
                	if(diff<divisor){
                    break;
                	}
            	}
            	cout<<"ans:"<<-1*i;
			}
			else if(divisor>dividend){
				cout<<"0";
			}
			else{
            	while(1){
                	diff=dividend-divisor;
                	dividend=diff;
                	i++;
                	if(diff<divisor){
                    break;
                	}
            	}
            	cout<<"ans:"<<i;
			}
        }
        
    }
    else{
    	cout<<"invalid";
	} 
    return 0;
}

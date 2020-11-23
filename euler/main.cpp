#include <iostream>
#include <cmath>
using namespace std;




int main() {
    int a,b,g;
    int sum=0;
    int pyth=0;
    bool basil = true;
 
    for(a=1; basil; a++)
        for(b=1; b<1000; b++)
            for(g=1; g<1000; g++){
                pyth= a*a + b*b;
                    sum = a+b+g;
            if(pyth==g*g && sum==1000) {cout<<"a is "<<a<<"b is "<<b<<"g is "<<g<<"abg is "<<a*b*g<<endl;basil=false;}
    
        
        }
    
    
   
    
    return 0;
}

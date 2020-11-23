
#include <iostream>
#include <string>
#include<cmath>
using namespace std;

long triangle_numbergen(int i);
int divisors(long d);


int main()
{

int i=0;
long triangle;
int count;
while(count<=500){
triangle = triangle_numbergen(i);
//cout<<triangle<<endl;
count = divisors(triangle);
//if(count>500) cout<<triangle;
//cout<<count<<endl;
i++;
}

cout<<triangle;


}

long triangle_numbergen(int i){
    long triangle=0;
    for(int j=1; j<=i; j++)
      triangle = triangle + j;
      
      return triangle;
}

int divisors(long d){
int count=0;
int sqrt1=sqrt(d);
for(int i=1; i<=sqrt1; i++)
 if(d%i==0) count+=2;
 
 if(sqrt1*sqrt1==d) count--;
    
return count;
}

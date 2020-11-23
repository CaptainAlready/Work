#include<iostream>
using namespace std;

int main()
{
    int count=0;
    int i;
    int j;
    
    for(i=1; count<20; i++)
        for(j=1; j<21; j++)
        {
            if(i%j==0) count++;
            else{
                count=0;
                break;}
        }
    cout<<i-1<<endl;
    
}

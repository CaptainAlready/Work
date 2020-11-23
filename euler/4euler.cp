#include <iostream>

using namespace std;
bool ispal(int n);
int main()
{
    int digit;
    long rev;
    int num;
    int n;
    int max=0;
   
   
    for(int i=100; i<999; i++)
    {
        for(int j=100; j<999; j++)
        {
            num =i*j;
            n=num;
            if(ispal(n) && n>max)  max=n;
        }
    }
    
    cout<<max<<endl;
    
}

bool ispal(int n)
{
    int num;
    int rev;
    int digit;
    do
    {
        digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10;
    } while (num != 0);
    if(n==rev) return true; else return false;
    
}




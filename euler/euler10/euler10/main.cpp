//
//  main.cpp
//  euler10
//
//  Created by Panos Kapetanidis on 22/02/2020.
//  Copyright © 2020 Panos Kapetanidis. All rights reserved.
//

#include <iostream>
using namespace std;
bool isprime(int n);



int main() {
    long long sum=2;
    for(int i=3; i<=2000000; i++){
        if(isprime(i)) sum+=i;
       
        
    }
      cout<<sum;
    
}
bool isprime(int n){
    bool basil=true;
    for(int i=2; i<=n-1; i++){
        if(n%i==0){
            basil=false;
            break;}
        }
    return basil;
        
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool isPrime(ll num){
    if(num==1)
        return false;
    if(num==2 || num==3)
        return true;
    
    for(int i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
ll greatestFactor(ll num){
    for(int i=num;i>=2;i--)
        if(num%i==0 && isPrime(i))
            return i;
}
int main(int argc, char const *argv[]){

    int count = 0;
    int i=1;
    while(count!=15){
        cout<<"Checking for i = "<<i<<"\n";
        ll temp = greatestFactor(i*i+1);
        // cout<<temp<<"\n";
        if(temp>=2*i){
            cout<<"Its a stormer number\n";
            count++;
            i++;
            continue;
        }
        // break;
        cout<<"False\n";
        i++;
    }
    return 0;
}

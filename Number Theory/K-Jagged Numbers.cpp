// Check whether N is K-Jagged 
// Look at smallest prime factor of N
// If that spf is >= K (N is a K jagged number)

// First 10 4-jagged number

#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num){
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
int spf(int num){
    for(int i=2;i*i<=num;i++)
        if(num%i==0)
            return i;
    return num;
}
bool is4Jagged(int num){
    return num>=4;
}
int main(int argc, char const *argv[])
{

    int count = 0;
    int i=1;
    while(count!=10){
        if(is4Jagged(spf(i))){
            cout<<i<<" ";
            count++;
        }
        i++;
    }
    return 0;
}

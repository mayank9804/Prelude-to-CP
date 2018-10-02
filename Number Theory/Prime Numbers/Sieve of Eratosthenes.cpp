#include <bits/stdc++.h>
using namespace std;

// Will find all prime number less than MAX
void sieveOfEratosthenes(vector<pair<int,bool>>& primes,int MAX){
    // Time complexity O(Nloglog(N))
    primes[0].second = false;
    primes[1].second = false;
    for(int i=2;i<MAX;i++)
        primes[i].second = true;
    
    for(int i=2;i<MAX;i++)
        for(int j=i+i;j<MAX;j+=i)
            primes[j].second = false;
}

int main(int argc, char const *argv[]){
    const int MAX = 10000;
    vector<pair<int,bool>>primes(MAX);
    sieveOfEratosthenes(primes,MAX);
    // Check whether 5,7,10 are primes
    cout<<primes[5].second<<"\n";
    cout<<primes[7].second<<"\n";
    cout<<primes[10].second<<"\n";

    
    return 0;
}

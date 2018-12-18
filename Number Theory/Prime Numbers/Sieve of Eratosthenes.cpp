#include <bits/stdc++.h>
using namespace std;

// Will find all prime number less than MAX
void sieveOfEratosthenes(vector<pair<int,bool>>& primes,int MAX){
    // Time complexity O(Nloglog(N))
    primes[0].second = false;
    primes[1].second = false;
    for(int i=2;i<MAX;i++)
        primes[i].second = true;
    
    for(int i=3;i*i<=MAX;i++)
        if(primes[i].second)
            for(int j=i+i;j<MAX;j+=i)
                primes[j].second = false;
}

int main(int argc, char const *argv[]){
    const int MAX = 10000;
    vector<pair<int,bool>>primes(MAX);
    sieveOfEratosthenes(primes,MAX);
    // Check whether 5,7,10 are primes
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        int count = 0;
        int i=0;
        while(count!=N){
            if(primes[i])
                count++;
            if(count==N)
                break;
            i++;
        }
        cout<<i*i+1<<'\n';
    }

    
    return 0;
}

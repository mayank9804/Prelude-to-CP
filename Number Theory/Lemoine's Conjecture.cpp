// Lemoine's Conjecture says that any +ve integer greater than 5
// can be represented as odd prime + even semiprimes(product of 2 primes )

// 7 = 3 + (2*3)
// 9 = 2 + (2*3)
// 17 = 3 + (2*7)


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
// Will find all prime number less than MAX
void sieveOfEratosthenes(vector<pair<int,bool>>& primes,int MAX){
    // Time complexity O(Nloglog(N))
    primes[0].second = false;
    primes[1].second = false;
    for(int i=2;i<MAX;i++)
        primes[i].second = true;
    
    for(int i=2;i<MAX;i++)
        if(primes[i].second)
            for(int j=i+i;j<MAX;j+=i)
                primes[j].second = false;
    
}

int main(int argc, char const *argv[]){
    int N;
    cin>>N;
    vector<pair<int,bool>>primes(N);
    sieveOfEratosthenes(primes,N);

    // unordered_map<int,int>trcK;

    for(int i=0;i<=N;i++){
        if(primes[i].second && 2*i<17){
            if(isPrime(17-(2*i))){
                cout<<(17-(2*i))<<" + ( 2 * "<<i<<" )\n";
            }
        }
    }
    
    return 0;
}


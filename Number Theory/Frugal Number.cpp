#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ci pair<char,int>
#define pb push_back
typedef unsigned long long ull;


vector<bool> sieve(int LIMIT){
    vector<bool>primes(LIMIT,true);
    primes[0] = false;
    primes[1] = false;

    for(int i=2;i*i<=LIMIT;i++)
        if(primes[i])
            for(int j=i+i;j<LIMIT;j++)
                if(j%i==0)
                    primes[j]=0;
    
    return primes;
}

int countDigs(int N){
    return to_string(N).size();
}
int main(int argc, char const *argv[]){

    int N;
    cin>>N;
    
    int digsNum = countDigs(N);
    int facNums=0;
    vector<bool>primes = sieve(N);

    FOR(i,0,sqrt(primes.size())+1){
        cout<<i<<"\n";
        if(primes[i] && N%i==0){
            facNums+= countDigs(i);
            int temp = 0;
            while(N%i==0 && N>0){
                N = N/i;
                temp++;
            }
            if(temp!=1)
                facNums+= countDigs(temp);
        }
    }
    cout<<digsNum<<" "<<facNums<<"\n";
    if(digsNum>facNums)
        cout<<"Frugal Number";
    else
        cout<<"Not a frugal number";
    return 0;
}

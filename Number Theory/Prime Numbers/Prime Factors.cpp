#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<pair<bool,int>>sieveOfAtkin(int limit){
    vector<pair<bool,int>>primes(limit);
    for(int i=0;i<limit;i++){
        if(i==2 || i==3)
            primes[i] = {true,i};
        else
            primes[i] = {false,i};
    }

    for(int x = 1;x*x<=limit;x++){
        for(int y = 1;y*y<=limit;y++){
    
            int n = (4 * x * x) + (y * y);
            if (n<limit && (n % 12 == 1 || n % 12 == 5))
                primes[n].first ^= true;
                
 
            n = (3 * x * x) + (y * y);    
            if (n<limit && n % 12 == 7)
                primes[n].first ^= true;
                
 
            n = (3 * x * x) - (y * y);
            if(n>=0 && n<limit)
                if (x > y && n % 12 == 11)
                    primes[n].first ^= true;

        }   
    }
    for(int r = 5; r * r < limit; r++){
        if(primes[r].first) {
            for (int i = r * r; i < limit; i += r * r)
                primes[i].first = false;
        }
    }
    return primes;
}
void printPrimeDivisors(int a,vector<pair<bool,int>>&primes){
    vector<int>arr;
    int i=0;
    while(a>1){
        while(primes[i].first && a%primes[i].second==0){
            if(find(arr.begin(),arr.end(),primes[i].second) == arr.end())
                arr.push_back(primes[i].second);
            a = a/primes[i].second;
        }
        i+=1;
    }
    for(auto e:arr){
        cout<<e<<" ";
    }
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int MAX = 10000;
    vector<pair<bool,int>>primes = sieveOfAtkin(MAX);
    int T,a;
    cin>>T;
    while(T){
        cin>>a;
        printPrimeDivisors(a,primes);
        T--;
    }
    return 0;
}
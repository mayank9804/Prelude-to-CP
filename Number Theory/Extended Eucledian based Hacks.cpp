#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ci pair<char,int>
#define pb push_back
typedef unsigned long long ull;

unordered_map<int,ull>fiboTRC;
ull fibo(int i){
    if(fiboTRC.find(i)!=fiboTRC.end())
        return fiboTRC[i];
    else{
        if(i==0)
            fiboTRC[i]=0;
        else if(i==1)
            fiboTRC[i]=1;
        else
            fiboTRC[i]=fibo(i-1)+fibo(i-2);
        
        return fiboTRC[i];
    }
}
int main(int argc, char const *argv[]){
    FAST;
    TEST;
    int i,j;
    while(T--){
        cin>>i>>j;
        // cout<<fibo(i)<<" "<<fibo(j)<<"\n";
        cout<<fibo(__gcd(i,j));
        cout<<"\n";
    }
    return 0;
}

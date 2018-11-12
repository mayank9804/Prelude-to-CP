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
// #define MOD 36123
typedef unsigned long long ull;
typedef long long ll;



ll power(ll a,ll b,ll MOD){
    if(b==0)
        return 1;
    
    ll sq = power(a,b/2,MOD);
    sq = (sq*sq)%MOD;

    if(b%2 == 1)
        return ((a%MOD)*(sq%MOD))%MOD;
    return sq%MOD;
}
int main(int argc, char const *argv[]){
    int B,P,M;
    while(cin>>B>>P>>M)
        cout<<power(B,P,M)<<"\n";
    return 0;
}

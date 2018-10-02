#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define pb push_back;
#define TEST int T;\
cin>>T;
typedef unsigned long long ull;

ull calcSum(stack<int>&s,int a){
    ull sum = 0;
    if(s.empty()){
        s.push(a);
        return sum;
    }else{
        if(s.size()!=0 && s.top()<a){
            while(!s.empty() && s.top()<a){
                sum+=a;
                s.pop();
            }
        }
        s.push(a);
    }
    return sum;
}
int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    int a,N;
    ull sum;
    while(T){
        sum = 0;
        stack<int>st;
        cin>>N;
        while(N){
            cin>>a;
            sum+=calcSum(st,a);
            N--;
        }
        cout<<sum<<"\n";
        T--;
    }

    return 0;
}

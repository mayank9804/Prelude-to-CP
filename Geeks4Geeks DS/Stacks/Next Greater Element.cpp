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

void insertInStack(stack<int>&s,int a,map<int,vector<int>>&arr){
    
    if(s.empty()){
        s.push(a);
    }else{
        if(s.size()!=0 && s.top()<a){
            while(!s.empty() && s.top()<a){
                if(arr.find(s.top())==arr.end())
                    arr[s.top()].pb(a);
                else
                    arr[s.top()] = {a};
                s.pop();
            }
        }
        s.push(a);
    }
    
}

int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    int a,N;
    map<int,vector<int>>arr;
    vector<int>inp;
    while(T){
        arr={};
        inp={};
        stack<int>st;
        cin>>N;
        while(N){
            cin>>a;
            inp.pb(a);
            N--;
        }
        FORI(i,0,inp.size()){
            insertInStack(st,inp[i],arr);
        }
        while(!st.empty()){
            arr[st.top()].pb(-1);
            st.pop();
        }
        FORI(i,0,inp.size()){
            cout<<arr[inp[i]][0]<<" ";
            // delete arr[inp[i]][0]
            arr[inp[i]].erase(arr[inp[i]].begin());
        }
        cout<<"\n";
        T--;
    }

    return 0;
}

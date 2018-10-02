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

void lvp(char c,stack<char>&s,int& counter,int& maxLength){
    if(c==')'){
        if(s.size()!=0 && s.top()!=')'){
            counter+=2;
            maxLength = maxLength>counter?maxLength:counter;
            s.pop();
        }else{
            counter = 0;
        }
    }else{
        // if(s.size()!=0 && s.top()==c)
        //     counter = 0;
        s.push(c);
        // How to reset counter!
    }
}

int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    string s;
    int counter,maxLength;
    while(T--){
        counter = 0;
        maxLength = 0;
        stack<char>st;
        cin>>s;
        FORI(i,0,s.size()){
            lvp(s[i],st,counter,maxLength);
        }
        cout<<maxLength<<"\n";
    }
    return 0;
}

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

void getUnbalancedString(stack<char>&s,char c){
    if(s.size()==0){
        s.push(c);
    }else{
        if(c=='}'){
            if(s.size()!=0 && s.top()=='{')
                s.pop();
            else
                s.push(c);
        }
        else{
            s.push(c);
        }
    }
}
int countMinReversal(stack<char>&s){
    int left = 0;
    int right = 0;
    while(!s.empty()){
        if(s.top()=='{')
            left++;
        else
            right++;
        s.pop();
    }   
    if((left+right)%2!=0)
        return -1;
    else{
        
       return ceil(left/2.0)+ceil(right/2.0);
    }
    
}
int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    string s;
    while(T--){
        stack<char>stck;
        cin>>s;
        FORI(i,0,s.size()){
            getUnbalancedString(stck,s[i]);
        }
        stack<char>duplicate(stck);
        cout<<countMinReversal(stck)<<"\n";
    }
    return 0;
}


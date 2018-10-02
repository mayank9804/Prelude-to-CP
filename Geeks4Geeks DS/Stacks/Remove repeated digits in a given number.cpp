#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define For(i,a,b) for(int i=a;i<b;i++)
typedef unsigned long long ull;

void insertInStack(stack<int>&st,int a){
    if(st.size()==0){
        st.push(a);
    }else{
        if(st.top()!=a)
            st.push(a);
    }
}
int main(int argc, char const *argv[]){
    FAST;
    TEST;
    string s;
    while(T){
        stack<int>st;
        cin>>s;
        For(i,0,s.size()){
            insertInStack(st,s[i]-48);
        }
        s="";
        while(!st.empty()){
            s+=(st.top()+48);
            st.pop();
        }
        
        reverse(s.begin(),s.end());
        cout<<s<<"\n";
        T--;
    }
    return 0;
}

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

void insertInStack(stack<int>&st,int elem){
    if(st.size()==0)
        st.push(elem);
    else if(st.top()<elem && st.size()>=2){
        cout<<st.top()<<" ";
         while(st.top()<elem && st.size()>=2){
            st.pop();
        }
        st.push(elem);
    }else{
        st.push(elem);
    }
}
// 41 114 121 149 178 304 345 428 657 752 766 799 918 
int main(int argc, char const *argv[]){
    FAST;
    TEST;
    int N,elem;
    while(T--){
        stack<int>st;
        cin>>N;
        while(N--){
            cin>>elem;
            insertInStack(st,elem);
        }
        if(!st.top()){
            cout<<st.top();
        }
        cout<<"\n";
    }
    return 0;
}

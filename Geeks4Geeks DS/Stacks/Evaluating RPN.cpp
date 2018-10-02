// RPN (Reverse Polish Notation)
// Evaluating RPN requires the usage of stack 
// Keep pushing the operand and if operator is found
// apply on top 2 elements and pop them pushing the resultant
// value.

#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define For(i,a,b) for(int i=a;i<b;i++)
#define ci pair<char,int>
typedef unsigned long long ull;

void dealWithStack(stack<int>&st,char c){
    if(c>=48 && c<=57){
        st.push(c-48);
    }else{
        if(!st.empty()){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch(c){
                case '*':
                    
                    st.push(a*b);
                    break;
                case '/':
                    
                    st.push(a/b);
                    break;
                case '+':
                    
                    st.push(a+b);
                    break;
                case '-':
                    
                    st.push(a-b);
                    break;
            }
        }
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
            dealWithStack(st,s[i]);
        }
        if(!st.empty())
            cout<<st.top()<<"\n";
        T--;
    }
    return 0;
}

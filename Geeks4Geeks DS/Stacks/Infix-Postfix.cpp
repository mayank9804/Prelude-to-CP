#include <bits/stdc++.h>
using namespace std;
// Infix to Postfix Conversion
// Operator precedence "*,/" > "+,-" > "^"

#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define For(i,a,b) for(int i=a;i<b;i++)
typedef unsigned long long ull;
#define constraints (s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='^' || s[i]=='*' || s[i]=='('||s[i]==')')

void postfixing(stack<char>&st,char c){ 
    
    if(st.empty() || c=='('){
        st.push(c);
    }else{
        if(c==')'){
            while(st.size()!=0 && st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            if(st.size()!=0)
                st.pop();
        }else if(c=='*'|| c=='/'){
            // Highest priority
            while(st.size()!=0 && st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }else if(c=='+'|| c=='-'){
            // Highest priority
            while(st.size()!=0 && (st.top()=='*' || st.top()=='/' || st.top()=='+' || st.top()=='-')){
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }else if(c=='^'){
            while(st.size()!=0 && st.top()=='^'){
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }
    }
}
int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    string s;
    while(T){
        stack<char>stc;
        cin>>s;
        For(i,0,s.size()){
            if constraints {
                postfixing(stc,s[i]);
            }else{
                cout<<s[i];
            }
        }
        while(!stc.empty()){
            cout<<stc.top();
            stc.pop();
        }
        cout<<"\n";
        T--;
    }
    return 0;
}

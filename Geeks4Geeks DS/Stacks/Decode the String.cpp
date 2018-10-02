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
bool isInt(string a){
    for(char e:a){
        if(e>=48 && e<=57)
            return true;
        else
            return false;
    }
}
void getCount(stack<string>&s,int& count){
    string st="";

    while(s.size()!=0 && isInt(s.top())){
        st+=s.top();
        s.pop();
    }

    if(st!=""){
        reverse(st.begin(),st.end());
        count = stoi(st);
    }
}
void popMe(stack<string>&s,string& op){
    while(s.size()!=0 && s.top()!="["){
        string temp = s.top();
        s.pop();
        popMe(s,op);
        op+=temp;
    }
    if(s.size()==0 || s.top()=="[")
        return;
}
string decodeMe(string s){
    stack<string>st;
    string optemp="";
    FORI(i,0,s.size()){
        if(s[i]!=']'){
            string temp;
            temp.pb(s[i]);
            st.push(temp);
        }
        else{
            popMe(st,optemp);
            if(!st.empty()){
                st.pop();
                if(!st.empty()){
                    string incdup="";
                    int count=0;
                    getCount(st,count);
                    while(count--){
                        incdup+=optemp;
                    }
                    optemp = incdup;
                    st.push(optemp);
                } 
            }
            if(i!=s.size()-1)
                optemp = "";
        }
    }
    return optemp;
}
int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    string s;
    while(T--){
        cin>>s;
        cout<<decodeMe(s)<<"\n";
    }
    return 0;
}

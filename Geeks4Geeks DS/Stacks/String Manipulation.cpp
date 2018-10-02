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

void insertInStack(stack<string>&s,string str){
    if(s.size()==0)
        s.push(str);
    else{
        if(s.top()!=str){
            s.push(str);
        }else{
            while(s.size()!=0 && s.top()==str){
                s.pop();
            }
        }
    }
}
int main(int argc, char const *argv[]){

    FAST;
    TEST;
    int N;
    string str;
    while(T){
        stack<string>s;
        cin>>N;
        while(N--){
            cin>>str;
            insertInStack(s,str);
        }
        int counter=0;
        while(!s.empty()){
            counter++;
            s.pop();
        }
        cout<<counter<<"\n";
        T--;
    }
    return 0;
}

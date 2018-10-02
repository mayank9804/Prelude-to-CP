// Given a bracket sequence or in other words a string S of length n, consisting of characters ‘(‘ and ‘)’. Find the length of the maximum correct bracket subsequence of sequence for a given query range. Note: A correct bracket sequence is the one that has matched bracket pairs or which contains another nested correct bracket sequence.
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

int main(int argc, char const *argv[])
{
    int counter,L,R;
    FAST;
    TEST;
    string bcr;
    
    while(T){
        counter = 0;
        stack<char>s;
        cin>>bcr;
        cin>>L>>R;
        if(R>=bcr.length())
            R = bcr.length()-1;
        for(int i=L;i<=R;i++){
            if(bcr[i]=='(')
                s.push('(');
            else if(bcr[i]==')'){
                if(s.size()==0)
                    continue;
                if(s.top()=='('){
                    counter+=2;
                    s.pop();
                }
                else
                    continue;
            }
        }
        cout<<counter<<"\n";
        T--;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define pb push_back;
#define TEST int T;\
cin>>T;

int main(int argc, char const *argv[]){
    FAST;
    TEST;
    string st;
    int counter;
    while(T){
        stack<char>s;
        cin>>st;
        
        for(char e:st){
            
            counter = 0;
            if(s.size()!=0 && tolower(e)!=s.top()){
                char a;
                // POP all do what is required
                while(!s.empty()){
                    counter++;
                    a = s.top();
                    s.pop();
                }
                cout<<counter<<a;
                s.push(tolower(e));
            }else{
                s.push(tolower(e));
            }
        }
        if(s.size()!=0){
            counter = 0;
            char temp = s.top();
            while(!s.empty()){
                counter++;
                s.pop();
            }
            cout<<counter<<temp;
        }
        cout<<"\n";
        T--;
    }
    return 0;
}

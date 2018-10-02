#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    string sp;
    cin>>T;
    while(T){
        cin>>sp;
        stack<pair<char,int>>s;
        
        int counter = 0;
        for(char e:sp){
            if(e=='('){
                counter++;
                s.push({'(',counter});
            }else if(e==')'){
                if(s.empty()){
                    continue;
                }else{
                    if(s.top().first==')'){
                        cout<<s.top().second<<" "<<s.top().second<<" ";
                        s.pop();
                    }
                }
            }
        }
        T--;
    }
    return 0;
}

/* Author: Mayank Sharma
email: mayank04111998@gmail.com
*/
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


int main(int argc, char const *argv[]){
    int N,a;
    cin>>N;
    int temp;
    unordered_map<int,bool>trc;
    FORI(i,0,N){
        cin>>a;
        if(i==0)
            temp =a;
        else
            temp = __gcd(a,temp);
        trc[a]= true;
    }
    if(trc.find(temp)!=trc.end())
        cout<<"True";
    else
        cout<<"False";
    cout<<"\n";
    return 0;
}



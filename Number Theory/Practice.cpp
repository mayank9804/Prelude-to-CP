#include <bits/stdc++.h>
using namespace std;


int gcd(int a,int b){
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
int gcdExtended(int a,int b,int &x,int &y){
    if(b==0){
        x=0;
        y=1;
        return a;
    }
    else{
        int x1,y1;
        int gcd = gcdExtended(b,a%b,x1,y1);
        x = y1 - (b/a) * x1; 
        y = x1; 
        cout<<a<<" "<<b<<"\n";
        cout<<x<<" "<<y<<"\n";
        return gcd;
    }
}
int main(int argc, char const *argv[]){
    // cout<<gcd(0,6)<<"\n";
    int x,y;
    cout<<gcdExtended(27,15,x,y);
    return 0;
}

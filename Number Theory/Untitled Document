#include <bits/stdc++.h>
using namespace std;

int egcd(int a,int b,int &x,int &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    egcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
}
int main(int argc, char const *argv[])
{
    int x,y;
    egcd(35,15,x,y);
    cout<<x<<" "<<y<<"\n";
    return 0;
}

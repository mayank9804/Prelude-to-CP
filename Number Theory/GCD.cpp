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
// [{4,1} {3,-1}]
//[{7,1}{4,-1}]
// [ {7,-1}{4,2}]
// [{11,2}{7,-3}]
// [{18,-3}{11,5}]
// [{497,5}{18,-156}]
// [{3000,-156}{497,-931}]

vector<pair<int,int>>arr;
void gcd(int a,int b){
    if(a%b==0)
        return;
    else{
        gcd(b,a%b);
        if(arr.size()==0){
            arr.pb({a,1});
            arr.pb({b,-(a/b)});
        }else{
            pair<int,int>temp1 = {a,1};
            pair<int,int>temp2 = {b,-(a/b)};
            temp1.second = temp1.second*(arr[1].second);
            temp2.second = temp2.second*(arr[1].second);
            temp2.second += arr[0].second;
            arr[0]=temp1;
            arr[1]=temp2;
        }
    }
}

int main(int argc, char const *argv[]){

    int a,b;
    cin>>a>>b;
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    gcd(a,b);
    for(auto e:arr)
        cout<<"Coefficient of : "<<e.first<<" "<<e.second<<"\n"; 
    
    
    
    return 0;
}

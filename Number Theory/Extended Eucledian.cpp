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

int temp;
int counter  = 0;
vector<int>primeFactors;

bool isPrime(int num){
    if(num==1)
        return false;
    if(num==2 || num==3)
        return true;
    
    for(int i=2;i*i<=num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}

void getPrimeFactors(int d){
    for(int i=2;i<=d;i++){
        if(d%i==0 && isPrime(i)){
            primeFactors.pb(i);
            while(d%i==0)
                d=d/i;
        }
    }
}

bool commonFactor(int temp){
    for(int i=0;i<primeFactors.size();i++){
        if(temp%primeFactors[i]==0)
            return true;
    }
    return false;
}
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
        if(commonFactor(arr[0].second))
            counter++;
        if(commonFactor(arr[1].second))
            counter++;
    }
}

int main(int argc, char const *argv[]){

    FAST;
    TEST;
    int a,b;
    while(T--){
        primeFactors={};
        cin>>a>>b;
        temp = __gcd(a,b);
        getPrimeFactors(temp);
        counter = 0;
        gcd(a,b);
        cout<<counter<<"\n";
    }
    
    
    return 0;
}

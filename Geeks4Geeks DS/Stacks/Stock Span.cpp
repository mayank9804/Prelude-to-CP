// What's the problem?
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days. 
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6


// The whole idea is to maintain a decreasing order in stack and for fast access indices are used in stack
// Now if the order is broken we pop until order reflects again
// Corresponding calculations on index would give span of particular stock price

#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ci pair<char,int>
#define ii pair<int,int>
#define pb push_back
typedef unsigned long long ull;

void insertInStack(stack<int>&s,int e,vector<int>&arr,vector<int>&spanArr,int x){
    if(s.empty()){
        s.push(x);
    }else{
        if(s.size()!=0 && arr[s.top()]<=e){
            while(s.size()!=0 && arr[s.top()]<=e){
                s.pop();
            }
            spanArr[x] = s.size()==0?x+1:x-s.top();
            s.push(x);
        }else{
            spanArr[x] = 1;
            s.push(x);
        }
    }
}

void doOperation(vector<int>&arr,stack<int>&stck){
    vector<int>spanArr(arr.size());
    stck.push(0);
    spanArr[0]=1;
    for(int i=1;i<arr.size();i++){
        insertInStack(stck,arr[i],arr,spanArr,i);
    }
    for(int e:spanArr){
        cout<<e<<" ";
    }
}
int main(){
    FAST;
    TEST;
    int N,a;
    vector<int>arr;
    while(T--){
        arr={};
        stack<int>stck;
        cin>>N;
        while(N--){
            cin>>a;
            arr.pb(a);
        }
        doOperation(arr,stck);
        cout<<"\n";
    }
}
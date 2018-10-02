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


void insertIntoStack(int index,vector<int>&arr,vector<int>&smallestElemArr,stack<int>&stck){
    if(stck.size()!=0 && arr[index]>arr[stck.top()]){
        smallestElemArr[index] = arr[stck.top()];
    }else{
        while(stck.size()!=0 && arr[stck.top()]>=arr[index]){
            stck.pop();
        }
        if(stck.size()==0){
            smallestElemArr[index] = -1;
        }else{
            smallestElemArr[index] = arr[stck.top()];
        }
    }
    stck.push(index);
}
int main(int argc, char const *argv[]){
    
    FAST;
    TEST;
    int N,a;
    vector<int>arr;
    while(T--){
        stack<int>s;
        arr={};
        cin>>N;
        vector<int>smallestElemArr(N);
        while(N--){
            cin>>a;
            arr.pb(a);
        }
        // Now i have the collection of integer element
        FORI(i,0,arr.size()){
            if(i!=0)
                insertIntoStack(i,arr,smallestElemArr,s);
            else{
                smallestElemArr[i] = -1;
                s.push(i);
            }
        }
        FORI(i,0,smallestElemArr.size()){
            cout<<smallestElemArr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

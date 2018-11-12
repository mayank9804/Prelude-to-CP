#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)


bool customSort(const pair<int,int>&a,const pair<int,int>&b){
    return (a.first/a.second >= b.first/b.second);
}
int main(int argc, char const *argv[]){
    
    int N;
    cin>>N;
    vector<pair<int,int>>arr(N);

    FORI(i,0,N)
        cin>>arr[i].first;
    FORI(i,0,N)
        cin>>arr[i].second;
    
    sort(arr.begin(),arr.end(),customSort);

    FORI(i,0,N)
        cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    return 0;
}

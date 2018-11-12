#include <bits/stdc++.h>
using namespace std;

bool customSort(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}
int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    vector<pair<int,int>>arr(N);
    
    for(int i=0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),customSort);

    int count = 0;
    int temp = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i].first>=temp){
            temp = arr[i].second;
            count++;
        }
        
    }
    cout<<count-1;
    return 0;
}

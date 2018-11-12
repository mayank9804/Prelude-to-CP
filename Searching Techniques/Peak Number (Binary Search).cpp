#include <bits/stdc++.h>
using namespace std;
#define FORI(i,a,b) for(int i=a;i<b;i++)

int searchMe(vector<int>&arr,int l,int r){
    if(r==l)
        return l;
    int mid = (l+r)/2;
    if(mid==arr.size()-1 || mid==0)
        return mid;
    if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])
        return mid;
    else if(arr[mid]<=arr[mid+1] && arr[mid]>=arr[mid-1])
        return searchMe(arr,mid+1,r);
    else if(arr[mid-1]>=arr[mid] && arr[mid+1]<=arr[mid])
        return searchMe(arr,l,mid-1);
    else if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
        
        if(arr[mid-1]>arr[mid+1])
            return searchMe(arr,l,mid-1);
        else
            return searchMe(arr,mid+1,r);
    }
}
int main(int argc, char const *argv[]){
    
    int N;
    cin>>N;
    vector<int>ARR(N);
    FORI(i,0,N)
        cin>>ARR[i];
    
    cout<<ARR[searchMe(ARR,0,N-1)]<<'\n';
    return 0;
}

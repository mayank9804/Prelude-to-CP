#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

/*
    Ordered Pairs which forms a given sum
*/


int N;
int lbound(int val,int l,int r,vector<int>&A){
    if(l>r)
        return -1;
    int mid = l+(r-l)/2;

    if(mid==l && A[mid]==val)
        return l;
    if(A[mid]==val && A[mid]!=A[mid-1])
        return mid;
    else if(A[mid]==val && A[mid]==A[mid-1])
        return lbound(val,l,mid-1,A);
    else if(A[mid]<val)
        return lbound(val,mid+1,r,A);
    return lbound(val,l,mid-1,A);
    
}
int ubound(int val,int l,int r,vector<int>&A){

    int mid = l+(r-l)/2;

    if(mid==r && A[mid]==val)
        return r;
    if(A[mid]==val && A[mid]!=A[mid+1])
        return mid;
    else if(A[mid]==val && A[mid]==A[mid+1])
        return ubound(val,mid+1,r,A);
    else if(A[mid]<val)
        return ubound(val,mid+1,r,A);
    return ubound(val,l,mid-1,A);
    
}
int main(){
    
    cin>>N;
    vector<int>ARR(N);
    for(int i=0;i<N;i++)
        cin>>ARR[i];
    
    int sum;
    cin>>sum;
    int ans = 0;
    for(int i=0;i<N;i++){
        int l = lbound(sum-ARR[i],i+1,N-1,ARR);
        if(l==-1)
            continue;
        int r = ubound(sum-ARR[i],i+1,N-1,ARR);
        ans+=(r-l+1);
    }
    cout<<ans;
    return 0;
}
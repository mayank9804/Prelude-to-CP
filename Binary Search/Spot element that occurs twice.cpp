#include <bits/stdc++.h>
using namespace std;

/*
    Given a sorted array containing numbers from 1 to n
    with one element twice. Spot that element.

    You may assume answer always exists.
*/


int bin(vector<int>&A,int l,int r){
    int mid = l+(r-l)/2;

    if(mid==0){
        if(A[mid+1]==A[mid])
            return A[mid];
    }
    if(mid==A.size()-1){
        if(A[mid]==A[mid-1])
            return A[mid];
    }
    if(A[mid-1]==A[mid] || A[mid]==A[mid+1])
        return A[mid];
    else if(A[mid]==mid)
        return bin(A,l,mid-1);
    else if(A[mid]==mid+1)
        return bin(A,mid+1,r);
}

int main(){

    int N;
    cin>>N;
    vector<int>ARR(N);
    for(int i=0;i<N;i++)
        cin>>ARR[i];
    cout<<bin(ARR,0,ARR.size()-1);
    return 0;
}
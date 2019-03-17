#include <bits/stdc++.h>
using namespace std;


/*
Given a sorted array of odd length with every element which occurs twice except once.
Find exception.
*/

vector<int>ARR;
int bin(int l,int r){
    if(ARR.size()==1)
        return ARR[0];
    int mid = (l+r)/2;
    
    if(mid==0){
        if(ARR[mid+1]!=ARR[mid])
            return ARR[mid];
    }
    else if(mid==ARR.size()-1){
        if(ARR[mid]!=ARR[mid-1])
            return ARR[mid];
    }
    else{
        if(ARR[mid]!=ARR[mid+1] && ARR[mid]!=ARR[mid-1])
            return ARR[mid];
        else if((ARR[mid-1]==ARR[mid] && mid%2==0) || (ARR[mid+1]==ARR[mid] && mid%2!=0)){
            return bin(l,mid-1);
        }else if((ARR[mid-1]==ARR[mid] && mid%2!=0) || (ARR[mid+1]==ARR[mid] && mid%2==0)){
            return bin(mid+1,r);
        }
    } 
}

int main(){
    int N;
    cin>>N;
    ARR.resize(N);
    for(int i=0;i<N;i++){
        cin>>ARR[i];
    }

    cout<<bin(0,N-1);
}
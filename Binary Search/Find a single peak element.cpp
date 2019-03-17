#include <bits/stdc++.h>
using namespace std;


int N;
vector<int>ARR;

int bin(int l,int r){
    if(ARR.size()==1)
        return ARR[0];

    int mid = l+(r-l)/2;

    if(mid==0 && ARR[mid+1]<ARR[mid])
        return ARR[mid];
    if(mid==N-1 && ARR[mid-1]<ARR[mid])
        return ARR[mid];
    
    if(ARR[mid]>=ARR[mid+1] && ARR[mid]>=ARR[mid-1])
        return ARR[mid];
    if(ARR[mid-1]>ARR[mid])
        return bin(l,mid-1);
    if(ARR[mid+1]>ARR[mid])
        return bin(mid+1,r);
}

int main(){
    
    cin>>N;
    ARR.resize(N);
    for(int i=0;i<N;i++)
        cin>>ARR[i];
    

    cout<<bin(0,N-1);
    return 0;
}
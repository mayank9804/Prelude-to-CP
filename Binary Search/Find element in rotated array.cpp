#include <bits/stdc++.h>
using namespace std;


int bin(int l,int r,int val,vector<int>&ARR){
    if(l>r)
        return -1;
    int mid = (l+r)/2;
    // cout<<l<<' '<<r<<' '<<mid<<'\n';
    if(ARR[mid]==val)
        return mid;
    else if(ARR[mid]<val){
        return bin(mid+1,r,val,ARR);
    }else if(ARR[mid]>val){
        if(val>ARR[ARR.size()-1] || ARR[mid] < ARR[ARR.size()-1]){
            return bin(l,mid-1,val,ARR);
        }else{
            return bin(mid+1,r,val,ARR);
        }
    }
}

int main(){
    int N;
    cin>>N;
    vector<int>ARR(N);
    for(int i=0;i<N;i++)
        cin>>ARR[i];
    
    int elem;
    cin>>elem;
    cout<<bin(0,N-1,elem,ARR);
    return 0;
}
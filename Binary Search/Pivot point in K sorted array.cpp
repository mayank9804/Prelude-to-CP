#include <bits/stdc++.h>
using namespace std;



/*

    K-rotated array: 0 1 2 3 4 5 
    3-rotated array: 3 4 5 0 1 2
    4 4 4 3 0 1 2
    
*/

int N;
vector<int>ARR;

int customBin(int l,int r){

    int mid = (l+r)/2;
    
    if(mid==0 || mid==N-1)
        return mid;

    if(ARR[mid]<ARR[mid+1] && ARR[mid]<ARR[mid-1])
        return mid;
    
    if(ARR[mid]<=ARR[ARR.size()-1])
        return customBin(l,mid-1);
    else if(ARR[mid]>ARR[ARR.size()-1])
        return customBin(mid+1,r);
    
    
}


int main(){
    
    cin>>N;
    ARR.resize(N);
    for(int i=0;i<N;i++)
        cin>>ARR[i];
    cout<<customBin(0,N-1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;



/*
    Find sqrt of number using binary search
*/

int N;
int customBin(int l,int r){

    if(l>r)
        return r;
    
    int mid = (l+r)/2;
    if(mid*mid==N)
        return mid;
    else if(mid*mid>N)
        return customBin(l,mid-1);
    
    return customBin(mid+1,r);
}


int main(){
    
    cin>>N;
    cout<<customBin(0,N);
    return 0;
}
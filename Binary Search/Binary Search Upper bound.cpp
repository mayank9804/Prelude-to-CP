#include <bits/stdc++.h>
using namespace std;

vector<int>ARR;

/*
    LOW, HIGH IF element is not present in array will give just lower,just next bigger element
*/


int customBin(int l,int r,int val){
    if(l>r){
        return ARR[0];
    }
    int m = (l+r)/2;

    if(ARR[m]==val)
        return ARR[m];
    if(ARR[m]<val && m<ARR.size()-1 && ARR[m+1]>val)
        return ARR[m+1];
    else if(ARR[m]<val && m>=ARR.size()-1)
        return -1;
    else if(ARR[m]<val)
        return customBin(m+1,r,val);
    return customBin(l,m-1,val);
}


int main(){
    int N;
    cin>>N;
    ARR.resize(N);
    for(int i=0;i<N;i++){
        cin>>ARR[i];
    }
    sort(ARR.begin(),ARR.end());
    int key;
    cin>>key;
    cout<<customBin(0,N-1,key);
    return 0;
}
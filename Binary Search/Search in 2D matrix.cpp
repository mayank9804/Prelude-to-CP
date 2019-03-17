#include <bits/stdc++.h>
using namespace std;

bool valid(int r,int c){
    return r>=0 && r<3 && c>=0 && c<4;
}
// log(mn)
bool bin(int l,int h,int elem,vector<vector<int>>&ARR){
    if(l>h)
        return 0;
    int mid = (l+h)/2;
    
    int r = mid/4;
    int c = mid%4;
    
    if(!valid(r,c))
        return 0;
    
    if(ARR[r][c]==elem)
        return 1;
    else if(ARR[r][c]<elem)
        return bin(mid+1,h,elem,ARR);
    else if(ARR[r][c]>elem)
        return bin(l,mid-1,elem,ARR);
}

int main(){

    vector<vector<int>>ARR(3,vector<int>(4));
    for(int i=0;i<3;i++)
        for(int j=0;j<ARR[i].size();j++)
            cin>>ARR[i][j];
        
    int elem;
    cin>>elem;
    cout<<bin(0,11,elem,ARR);
    return 0;
}
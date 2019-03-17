#include <bits/stdc++.h>
using namespace std;

/*

Given a N cross M matrix in which each row is sorted, find the overall median of
the matrix. Assume N*M is odd.

*/

int main(){
    int n,m;
    cin>>n>>m;
    // row col
    vector<vector<int>>ARR(n,vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>ARR[i][j];
    
    int l,r;
    l = INT32_MAX;
    r = -1;
    for(int i=0;i<n;i++){
        l = min(l,ARR[i][0]);
        r = max(r,ARR[i][m-1]);
    }
    
    // l ........ h
    int ind = (m*n)/2;
    int ans;

    while(l<=r){
        int mid = (l+r)/2;
        
        // can mid be median? will mid occur on indth position in sorted array
        bool flag = 0;
        int p1 = 0;
        int p2 = 0;

        for(int i=0;i<n;i++){
            vector<int>::iterator itr  = lower_bound(ARR[i].begin(),ARR[i].end(),mid);
            if(*itr == mid)
                flag = 1;
            p1+= (itr-ARR[i].begin());
            p2+= (upper_bound(ARR[i].begin(),ARR[i].end(),mid)-ARR[i].begin());
            
        }
        
        if(!flag){
            // this mid was not present;
            if(p1<=ind){
                l = mid+1;
            }else if(p1>ind){
                r = mid-1;
            }
        }else{
            if(p1<=ind && (p2-1)>=ind){
                // this is going to be median
                ans = mid;
                break;
            }
            if(max(p1,p2-1)<ind){
                l = mid+1;
            }else if(min(p1,p2-1)>ind){
                r = mid-1;
            }
        }
        
    }
    cout<<ans<<'\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>ARR(r,vector<int>(c));

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>ARR[i][j];

   

    

    int sr = 0;
    int sc = 0;
    int er = r-1;
    int ec = c-1;
    int row;
    while(sr<=er && sc<=ec){

        
        for(int i = sc;i<=ec;i++)
            cout<<ARR[sr][i]<<' ';
        sr++;
        for(int i=sr;i<=er;i++)
            cout<<ARR[i][ec]<<' ';
        ec-=1;
        if(sr<=er){
        for(int i=ec;i>=sc;i--)
            cout<<ARR[er][i]<<' ';
        }
        er-=1;
        if(sc<=ec){
        for(int i=er;i>=sr;i--)
            cout<<ARR[i][sc]<<' ';
        }
        sc+=1;
        cout<<'\n';

    }

    return 0;
}
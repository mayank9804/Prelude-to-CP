#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<vector<int>>ADJL;

int main(){
    int N;
    cin>>N;
    int edge;
    cin>>edge;
    ADJL.resize(N+1,vector<int>{});
    int src,des;
    for(int i=0;i<edge;i++){
        cin>>src>>des;
        ADJL[src].pb(des);
    }

    vector<int>ANCESTORS(N+1,0);
    queue<int>Q;
    Q.push(1);
    ANCESTORS[1] = -1;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(int i=0;i<ADJL[node].size();i++){
            ANCESTORS[ADJL[node][i]] = node;
            Q.push(ADJL[node][i]);
        }
    }

    // for(int i=1;i<ANCESTORS.size();i++){
    //     cout<<ANCESTORS[i]<<' ';
    // }
    // cout<<'\n';

    int snode,k;
    cin>>snode>>k;
    int ans;
    
    while(k--){
        ans = ANCESTORS[snode];
        if(ans==-1)
            break;
        snode = ANCESTORS[snode];
    }
    cout<<ans<<'\n';

    return 0;
}
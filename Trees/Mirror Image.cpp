#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ARR;
map<int,int>LVL;
map<int,vector<int>>LNODES;
int main(){
    int N,qq,par,child;
    char dir;
    cin>>N>>qq;
    ARR.resize(N+1,vector<int>(2,-1));
    
    for(int i=1;i<N;i++){
        cin>>par>>child>>dir;
        if(dir=='L')
            ARR[par][0]=child;
        else if(dir=='R')
            ARR[par][1]=child;
    }
    
    queue<int>Q;
    Q.push(1);
    
    int level = 0;
    LNODES[level] = {1};

    while(!Q.empty()){
        int sz = Q.size();
        int count =0;
        while(sz--){
            int node = Q.front();

            if(node!=-1){
                LVL[node]=level;
            }else{
                count++;
            }
            Q.pop();
            for(int i=0;i<2;i++){
                if(node!=-1 && ARR[node][i]!=-1){
                    Q.push(ARR[node][i]);
                    LNODES[level+1].push_back(ARR[node][i]);
                }else{
                    Q.push(-1);
                    LNODES[level+1].push_back(-1);
                }
            }
        }
        if(count==pow(2,level))
            break;
        level++;
    }

    while(qq--){
        int ss;
        cin>>ss;
        int lv = LVL[ss];
        int nodes =pow(2,lv);
        int in = find(LNODES[lv].begin(),LNODES[lv].end(),ss)-LNODES[lv].begin();
        // cout<<in<<' ';
        int ind = abs(nodes-in);
        // cout<<ind<<'\n';
        cout<<LNODES[lv][ind-1]<<'\n';
    }
    return 0;
}
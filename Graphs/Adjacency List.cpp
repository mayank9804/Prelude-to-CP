#include <bits/stdc++.h>
using namespace std;

// vector<int>nodes;
void addEdge(int a,int b,vector<vector<int>>&adjL){
    // Undirected Graph
    if(adjL[a].size()==0)
        adjL[a]={};
    if(adjL[b].size()==0)
        adjL[b]={};
    adjL[a].push_back(b);
    adjL[b].push_back(a);
}

void DFS_UTIL(int srcI,vector<vector<int>>&adjL,vector<bool>&visited){
    visited[srcI]=true;
    cout<<"Dealing with vertex no: "<<srcI<<"\n";
    for(int i=0;i<adjL[srcI].size();i++){
        if(!visited[adjL[srcI][i]]){
            DFS_UTIL(adjL[srcI][i],adjL,visited);
        }
    }
}
void DFS(vector<vector<int>>&adjL,int V){
    vector<bool>visited(V,false);
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS_UTIL(i,adjL,visited);
        }
    }
}
int main(int argc, char const *argv[]){
    int V =5;
    vector<vector<int>>adjL(V);
    
    addEdge(0,1,adjL);
    addEdge(0,4,adjL);
    addEdge(1,2,adjL);
    addEdge(1,3,adjL);
    addEdge(1,4,adjL);
    addEdge(2,3,adjL);
    addEdge(3,4,adjL);
    
    DFS(adjL,V);
    return 0;
}

// Linear ordering of a graph can be considered only for Directed Acyclic Graph
// If graph contains cycle it cannot be linearly ordered
// Any DAG can be linearly ordered

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph{
    int v;
    vector<vector<int>>adjL;
    void topologicalSortUtil(int src,vector<bool>&visited,vector<bool>&deadEnd);
    public:
        Graph(int v);
        void addEdge(int a,int b);
        void topologicalSort(int src);
};
Graph::Graph(int V){
    this->v = V+1;
    adjL.resize(V+1);
    for(int i=0;i<V+1;i++)
        adjL[i]={};
}
void Graph::addEdge(int a,int b){
    // Directed graph
    adjL[a].pb(b);
}
void Graph::topologicalSortUtil(int src,vector<bool>&visited,vector<bool>&deadEnd){
    visited[src] = true;

    for(int i=0;i<adjL[src].size();i++){
        if(deadEnd[adjL[src][i]] && !visited[adjL[src][i]]){
            visited[adjL[src][i]]=true;
            cout<<adjL[src][i]<<" ";
            continue;
        }
        if(!visited[adjL[src][i]]){
            topologicalSortUtil(adjL[src][i],visited,deadEnd);
            cout<<adjL[src][i]<<" "; 
            deadEnd[adjL[src][i]] = true;
            // visited[adjL[src][i]] = true;
        }
    }
    
}
void Graph::topologicalSort(int src){
    vector<bool>visited(this->v,false);
    vector<bool>deadEnd(this->v,false);
    for(int i=1;i<adjL.size();i++){
        
        if(adjL[i].size()==0)
            deadEnd[i] = true;
    }
    for(int i=1;i<this->v;i++){
        if(!visited[i]){
            topologicalSortUtil(i,visited,deadEnd);
            cout<<i<<" ";
        }
    }
    
    // Start with this node and go to deadend
    // Remove deadend
    // Previous node will be new deadend

}
int main(int argc, char const *argv[])
{
    Graph g(5); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    g.addEdge(1, 3); 
    g.addEdge(1, 5); 
    // g.addEdge(2, 3); 
    // g.addEdge(3, 1); 

    cout<<"Graph created successfully\n";
    g.topologicalSort(0);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph{
    //No of vertices
    int v; 
    // Adjacency List
    vector<vector<int>>adj;

    public:
        Graph(int V);
        void addEdge(int V,int W);
        void DFS();
        void DFS_UTILITY(int s,vector<bool>&visited);
};
Graph::Graph(int V){
    this->v = V;
    adj.resize(V);
    for(int i=0;i<V;i++)
        adj[i] = vector<int>(V);
}
void Graph::addEdge(int V,int W){
    adj[V].pb(W);
    adj[W].pb(V);
}
void Graph::DFS_UTILITY(int s,vector<bool>&visited){
    cout<<"Dealing with node : "<<s<<"\n";
    visited[s] = true;
    for(int i=0;i<adj[s].size();i++){
        if(!visited[adj[s][i]]){
            DFS_UTILITY(adj[s][i],visited);
        }
    }
}
void Graph::DFS(){
    vector<bool>visited(this->v,false);
    for(int i=0;i<this->v;i++){
        if(!visited[i])
            this->DFS_UTILITY(i,visited);
    }
}
int main(int argc, char const *argv[]){
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    cout<<"****************DFS*******************\n";
    cout<<"DFS for Graph G: \n";
    g.DFS();
    return 0;
}

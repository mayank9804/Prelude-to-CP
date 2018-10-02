#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph{
    int v;
    vector<vector<int>>adjL;
    bool CycleUtility(int s,vector<bool>&visited,int parent);

    public:
        Graph(int v);
        void addEdge(int a,int b);
        bool isCyclic();
};

Graph::Graph(int V){
    this->v = V;
    adjL.resize(V);
    for(int i=0;i<V;i++)
        adjL[i] = vector<int>(0);
}
void Graph::addEdge(int a,int b){
    // Undirected edges
    adjL[a].pb(b);
    adjL[b].pb(a);
}
bool Graph::CycleUtility(int src,vector<bool>&visited,int parent){
    // Visited source and it is now part of simulated recursion stack
    visited[src]=true;
    
    // Explore src
    for(int i=0;i<adjL[src].size();i++){
        if(!visited[adjL[src][i]]){
            if(CycleUtility(adjL[src][i],visited,src))
                return true;
        }else if(adjL[src][i]!=parent){
            return true;
        }
    }
    return false;
}
bool Graph::isCyclic(){

    for(int i=0;i<this->v;i++){
        vector<bool>visited(this->v,false);
        vector<bool>recPart(this->v,false);
        vector<int>parents(this->v,-1);
        if(CycleUtility(i,visited,-1))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[]){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    // g.addEdge(1,2);

    g.isCyclic()?cout<<"Cycle detected in graph\n":cout<<"No Cycle present\n";
    return 0;
}

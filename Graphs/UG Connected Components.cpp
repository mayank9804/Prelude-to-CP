// IN undirected graph we talk about connectivity
// in terms of connected components
// IN DG, its strongly connected components
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Graph{
    int v;
    vector<vector<int>>adjL;
    void displayCC_UTIL(int s,vector<bool>&visited);
    public:
        Graph(int v);
        void displayConnectedComponents();
        void addEdge(int a,int b);
};
Graph::Graph(int V){
    this->v = V;
    adjL.resize(V);
    for(int i=0;i<V;i++)
        adjL[i] = {};
}
void Graph::addEdge(int a,int b){
    // Undirected graph
    adjL[a].pb(b);
    adjL[b].pb(a);
}
void Graph::displayCC_UTIL(int s,vector<bool>&visited){
    cout<<s<<" ";
    visited[s]=true;
    for(int i=0;i<adjL[s].size();i++){
        if(!visited[adjL[s][i]])
            displayCC_UTIL(adjL[s][i],visited);
    }
}
void Graph::displayConnectedComponents(){
    vector<bool>visited(this->v,false);
    for(int i=0;i<this->v;i++){
        if(!visited[i]){
            cout<<"Connected Component: \n";
            displayCC_UTIL(i,visited);
            cout<<"\n";
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.displayConnectedComponents();
    return 0;
}

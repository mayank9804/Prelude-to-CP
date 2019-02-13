#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Graph{
    //No of vertices
    int v; 
    // Pointer to an array containing adjacency lists 
    vector<vector<int>>adj;

    public:
        Graph(int V);
        void addEdge(int V,int W);
        void BFS(int s);
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
void Graph::BFS(int s){
    vector<bool>visited(this->v,false);
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int temp = q.front();
        
        cout<<"Dealing with "<<temp<<"\n";
        q.pop();
        for(int i=0;i<adj[temp].size();i++){
            if(!visited[adj[temp][i]]){
                q.push(adj[temp][i]);
                visited[adj[temp][i]]=true;
            }
        }
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

    cout<<"*****************BFS*****************\n";
    int temp;
    cout<<"Which node do you want to run BFS on?\n";
    cin>>temp;
    cout<<"BFS for node "<<temp<<" : \n";
    g.BFS(temp);

    return 0;
}

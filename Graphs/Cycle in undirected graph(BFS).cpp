#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph{
    int v;
    vector<vector<int>>adjL;
    bool CycleUtility(int s,vector<bool>&visited,vector<int>&parents);

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
bool Graph::CycleUtility(int src,vector<bool>&visited,vector<int>&parents){
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(int i=0;i<adjL[temp].size();i++){
            if(!visited[adjL[temp][i]]){
                visited[adjL[temp][i]]=true;
                q.push(adjL[temp][i]);
                parents[adjL[temp][i]] = temp;
            }
            else if(adjL[temp][i]!=parents[temp]){
                return true;
            }
        }
    }
    return false;
}
bool Graph::isCyclic(){

    for(int i=0;i<this->v;i++){
        vector<bool>visited(this->v,false);
        vector<int>parents(this->v,-1);
        if(CycleUtility(i,visited,parents))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[]){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    // g.addEdge(0,3);
    // g.addEdge(1,2);

    g.isCyclic()?cout<<"Cycle detected in graph\n":cout<<"No Cycle present\n";
    return 0;
}

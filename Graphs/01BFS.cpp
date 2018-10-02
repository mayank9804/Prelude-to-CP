#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph{
    int v;
    vector<vector<pair<int,int>>>adjM;
    
    public:
        Graph(int V);
        void addEdge(int a,int b,int wt);
        void BFS01(int src);
};
Graph::Graph(int V){
    this->v = V;
    adjM.resize(V);
    for(int i=0;i<V;i++)
        adjM[i] = {};
}
void Graph::addEdge(int a,int b,int wt){
    adjM[a].pb({b,wt});
    adjM[b].pb({a,wt});
}

void Graph::BFS01(int src){
    vector<int>dist(this->v,INT_MAX);
    deque<int>q;
    q.push_back(src);
    dist[src] = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop_front();

        for(int i=0;i<adjM[temp].size();i++){
            if(dist[adjM[temp][i].first]>dist[temp]+adjM[temp][i].second){
                dist[adjM[temp][i].first] = dist[temp]+adjM[temp][i].second;
                if(adjM[temp][i].second==0)
                    q.push_front(adjM[temp][i].first);
                else
                    q.push_back(adjM[temp][i].first);
            }
        }
    }
    for(int i=0;i<dist.size();i++)
        cout<<"Distance of node "<<i<<" from "<<src<<" is: "<<dist[i]<<"\n";
}
int main(int argc, char const *argv[]){
    
    Graph g(4);
    g.addEdge(0, 1, 0); 
    g.addEdge(0, 2, 1); 
    g.addEdge(1, 2, 0); 
    g.addEdge(1, 3, 1); 
    g.addEdge(3, 2, 1); 

    g.BFS01(0);
    return 0;
}

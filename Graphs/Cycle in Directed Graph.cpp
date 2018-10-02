#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph{
    int v;
    vector<vector<int>>adjM;
    bool isCyclicUtility(int s,vector<int>&visited,vector<int>&recPart,int fd);
    public:
        Graph(int V);
        void addEdge(int a,int b);
        void isCyclic();
};
Graph::Graph(int V){
    this->v = V;
    adjM.resize(V);
    for(int i=0;i<V;i++)
        adjM[i] = {};
}
void Graph::addEdge(int a,int b){
    adjM[a].pb(b);
}
bool Graph::isCyclicUtility(int src,vector<int>&visited,vector<int>&recPart,int fd){

    if(!visited[src]){
        visited[src] = true;
        recPart[src] = true;
        for(int i=0;i<adjM[src].size();i++){
            if(!visited[adjM[src][i]] && isCyclicUtility(adjM[src][i],visited,recPart,fd)){
                return true;
            }
            if(recPart[adjM[src][i]] && adjM[src][i]==fd){
                return true;
            }
        }
    }
    // If its already visited and there was no cycle 
    // return false and remove it from stack;
    // cout<<"No cycle found";
    recPart[src]=false;
    return false;
}
void Graph::isCyclic(){

    for(int i=0;i<this->v;i++){
        vector<int>visited(this->v,false);
        vector<int>recPart(this->v,false);
        if(isCyclicUtility(i,visited,recPart,i)){
            cout<<"Cycle detected\n";
            return;
        }
        else
            continue;
    }
    cout<<"No cycle detected\n";
}
int main(int argc, char const *argv[]){
    Graph g(4); 
    // g.addEdge(0, 1);
    // g.addEdge(0, 2); 
    // g.addEdge(1, 0); 
    // g.addEdge(2, 0); 
    // g.addEdge(2, 3); 
    // g.addEdge(1, 3);
    // g.addEdge(1, 2);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(1,0);
    // if(g.isCyclic()) 
    //     cout << "Graph contains cycle"; 
    // else
    //     cout << "Graph doesn't contain cycle"; 
    
    g.isCyclic();
    return 0;
}

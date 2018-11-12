/* Author: Mayank Sharma
email: mayank04111998@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);\
cin.tie(NULL);
#define TEST int T;\
cin>>T;
#define FORI(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ci pair<char,int>
#define pb push_back
typedef unsigned long long ull;

class Graph{
    private:
        int v;
        vector<vector<int>>adjL;
    public:
        Graph(int V);
        void addEdge(int src,int dest);
        bool bp_util();
        bool isBipartite(int src,vector<bool>&is_visited,vector<int>&color);
};
Graph::Graph(int V){
    this->v = V;
    adjL.resize(V);
    FORI(i,0,adjL.size())
        adjL[i]={};
}
void Graph::addEdge(int src,int dest){
    // Directed graph
    adjL[src].pb(dest);
}
// Using m color theorem with BFS 
bool Graph::isBipartite(int src,vector<bool>&is_visited,vector<int>&color){
    is_visited[src]=1;
    //  0 1 two colors
    color[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        FORI(i,0,this->adjL[curr].size()){
            if(color[adjL[curr][i]]!=-1 && color[adjL[curr][i]]!=!color[curr])
                return false;
            else if(color[adjL[curr][i]]!=-1)
                return true;
            is_visited[adjL[curr][i]]=1;
            color[adjL[curr][i]]=!color[curr];
            q.push(adjL[curr][i]);
        }
    }
    return true;
}
// To handle unconnected components
bool Graph::bp_util(){
    vector<bool>is_visited(this->v,false);
    vector<int>color(this->v,-1);
    for(int i=0;i<this->v;i++)
        if(!is_visited[i])
            if(!isBipartite(i,is_visited,color))
                return false;
    return true;
}
// Can also be done by dfs simply keep exploring node until you hit colored
// node. Then you can check whether the graph can be colored or not

int main(int argc, char const *argv[]){
    
    Graph g1(6);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.addEdge(4,5);
    g1.addEdge(5,0);

    Graph g2(5);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
    g2.addEdge(4,0);

    if(g1.bp_util())
        cout<<"Graph 1 is bipartite\n";
    else
        cout<<"Graph 1 is not bipartite\n";

    if(g2.bp_util())
        cout<<"Graph 2 is bipartite\n";
    else
        cout<<"Graph 2 is not bipartite\n";
    return 0;
}

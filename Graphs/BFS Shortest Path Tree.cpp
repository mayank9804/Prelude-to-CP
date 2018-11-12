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
        vector<int> path(int src,int dest);
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
vector<int> Graph::path(int src,int dest){
    vector<bool>visited(this->v,false);
    vector<int>par(this->v,-1);
    queue<int>q;
    q.push(src);
    visited[src]=true;
    bool done = false;
    while(!q.empty() && !done){
        int cur = q.front();
        q.pop();
        for(int i=0;i<adjL[cur].size();i++){
            visited[adjL[cur][i]]=true;
            q.push(adjL[cur][i]);
            par[adjL[cur][i]]=cur;
            if(adjL[cur][i] == dest){
                // We are done;
                done = true;
                break;
            }
        }
    }
    vector<int>path;
    while(dest!=-1 && done){
        path.pb(dest);
        dest = par[dest];
    }
    if(!done)
        path.pb(-1);
    reverse(path.begin(),path.end());
    return path;
}
int main(int argc, char const *argv[]){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);

    vector<int>path = g.path(0,4);
    FORI(i,0,path.size())
        cout<<path[i]<<' ';
    cout<<'\n';
    return 0;
}

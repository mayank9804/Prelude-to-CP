#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct Edge{
    int src;
    int des;
    Edge(int a,int b):src(a),des(b){}
};
struct Subset{
    int parent;
    int rank;
};
class Graph{
    private:
        int V;
        int E;
        vector<Edge>edges;
        vector<Subset>subsets;
    public:
        Graph(int v,int e);
        void addEdge(int src,int des);
        bool isCycle();
        int find(int parOf);
        void Union(int x,int y);
};

Graph::Graph(int v,int e){
    this->V=v;
    this->E=e;
    this->edges={};
    this->subsets.resize(this->V);
    for(int i=0;i<this->V;i++){
        this->subsets[i].parent = i;
        this->subsets[i].rank = 0;
    }
}
void Graph::addEdge(int src,int des){
    Edge e(src,des);
    this->edges.pb(e);
}

int Graph::find(int parOf){
    // Uses Path Compression technique
    if(this->subsets[parOf].parent!=parOf)
        this->subsets[parOf].parent=find(this->subsets[parOf].parent);
    return this->subsets[parOf].parent;
}
void Graph::Union(int x,int y){
    Subset &XX = this->subsets[x];
    Subset &YY = this->subsets[y];
    if(XX.rank>YY.rank){
        YY.parent = x;
        XX.rank++;
    }else if(XX.rank<YY.rank){
        XX.parent = y;
        YY.rank++;
    }else{
        XX.parent = y;
        YY.rank++;
    }
}
bool Graph::isCycle(){
    for(int i=0;i<edges.size();i++){
        int a = edges[i].src;
        int b = edges[i].des;
        int x = find(a);
        int y = find(b);
        if(x==y)
            return true;
        this->Union(x,y);
    }
    return false;
}
int main(){
    Graph g(3,3);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    // Detecting Cycle using Disjoint Set Data structure
    // which furthur uses Union Find algorithm

    if(g.isCycle())
        cout<<"Graph contains cycle\n";
    else
        cout<<"Graph does not contain cycle\n";
    return 0;
}
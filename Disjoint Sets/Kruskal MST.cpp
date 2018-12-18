#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct Edge{
    int src,des,weight;
    Edge(int a,int b,int c):src(a),des(b),weight(c){}
};
struct Info{
    int parent;
    int rank;
};
class Graph{
    private:
        int V,E;
        vector<Edge>edges;
        vector<Info>subsets;
    public:
        Graph(int v,int e);
        void addEdge(int a,int b,int c);
        int find(int parOf);
        void Union(int x,int y);
        void Kruskal();
};
Graph::Graph(int v,int e){
    this->V=v;
    this->E=e;
    this->edges={};
    this->subsets.resize(this->V);
    for(int i=0;i<this->V;i++){
        this->subsets[i].parent = i; 
        this->subsets[i].rank=1;
    }
}
void Graph::addEdge(int a,int b,int c){
    Edge t(a,b,c);
    this->edges.pb(t);
}
int Graph::find(int parOf){
    // Path Compression
    Info &II = this->subsets[parOf];
    if(II.parent!=parOf)
        return II.parent = find(II.parent);
    else
        return II.parent;
}
void Graph::Union(int x,int y){
    Info &XX=this->subsets[x];
    Info &YY=this->subsets[y];

    if(XX.rank>YY.rank){
        YY.parent = x;
        XX.rank++;
    }else if(XX.rank<=YY.rank){
        XX.parent = y;
        YY.rank++;
    }
}
bool csort(const Edge& a,const Edge& b){
    return a.weight<b.weight;
}
void Graph::Kruskal(){
    sort(this->edges.begin(),this->edges.end(),csort);

    int e = 0;
    int v = this->V;
    vector<Edge>MST;
    int ind = 0;

    while(e<v-1){
        int x = this->edges[ind].src;
        int y = this->edges[ind].des;
        int subsX = this->find(x);
        int subsY = this->find(y);

        if(subsX!=subsY){
            this->Union(subsX,subsY);
            MST.pb(edges[ind]);
            e+=1;
        }
        ind++;
    }

    for(int i=0;i<MST.size();i++){
        cout<<MST[i].src<<' '<<MST[i].des<<'\n';
    }
}
int main(){
    Graph g(3,3);
    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(2,1,5);
    // g.addEdge(1,3,15);
    // g.addEdge(2,3,4);

    g.Kruskal();
    return 0;
}
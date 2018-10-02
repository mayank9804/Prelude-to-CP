#include <bits/stdc++.h>
using  namespace std;


void addEdge(int a,int b,vector<vector<int>>&adjM){
    adjM[a][b] = 1;
}

int main(int argc, char const *argv[]){
    int V=5;
    vector<vector<int>>adjM(V);
    for(int i=0;i<V;i++)
        adjM[i] = vector<int>(V);
    addEdge(0,1,adjM);
    addEdge(0,4,adjM);
    addEdge(1,2,adjM);
    addEdge(1,3,adjM);
    addEdge(1,4,adjM);
    addEdge(2,3,adjM);
    addEdge(3,4,adjM);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<adjM[i][j]<<" ";
        cout<<"\n";
    }
    

    return 0;
}

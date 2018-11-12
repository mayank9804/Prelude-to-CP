// Two vertices (v,w) in a directed graph are connected if you
// can reach v from w and can reach w from v

// A Directed Graph can be partitioned into strongly connected
// components where two vertices are connected if and only if 
// they are in same component

// The metagraph of a DAG is always a DAG

// A directed graph is strongly connected if there is a path between all pairs of vertices.

// Can be implemented using Kosaraju's Algorithm

// The basic idea is to start from a node and explore all nodes
// reachable from that node (That's exactly a SCC)
// But chances are you could end up including nodes which are part of other component
// But when you are in Sink SCC, you exactly find a SCC

// TARGET: NEED a way to find a SINK SCC

// Theorem: If C and C' are two strongly connected components with an edge from some 
// vertex of C to some vertex of C', then largest post in C bigger than largest post in C'
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void adjmatrix(){
  int n,e;    // n -> nodes, m -> edges
    cin>>n>>e;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // we can only use adjacency matrix when the size of input is small
}
void adjlist(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void adjlistDirectedGraph(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
}

void adjListDirectegWeightedGraph(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adj[n+!];
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
}
int main()
{
    adjmatrix();
    adjlist();
    return 0;
}
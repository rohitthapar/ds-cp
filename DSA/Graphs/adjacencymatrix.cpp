#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void adjmatrix(){
  int n,e;    // n -> nodes, m -> edges
    cin>>n>>e;
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // we can only use adjacency matrix when the size of input is small
}
int main()
{
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& team){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(vis[i]){
            if(team[node] == team[i]) return false;
        } else {
            vis[i] = 1;
            team[i] = 1 - team[node];
            if(!dfs(i, adj, vis, team)) return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1,0);
    vector<int> team(n+1, -1);
    bool flag = false;
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            team[i] = 0;
            flag = dfs(i, adj, vis, team);
            if(!flag) break;
        }
    }
    if(!flag) cout << "IMPOSSIBLE";
    else {
        for(int i=1;i<=n;i++) cout << team[i]+1 << " ";
    }
    return 0;
}

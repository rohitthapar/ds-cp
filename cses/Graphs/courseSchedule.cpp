#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1), vis(n+1,0);
    bool flag = false;
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for(int i=1;i<indeg.size();i++){
        if(indeg[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    if(q.empty()) flag = true;
    vector<int> res;
    while(!q.empty()){
        int node = q.front(); q.pop();
        res.push_back(node);
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0 && vis[it] != 1) {
                q.push(it);
                vis[it] = 1;
            } else if(indeg[it] != 0 && vis[it] == 1) {
                flag = true;
                break;
            }
        }
    }
    if(flag == true) cout << "IMPOSSIBLE" << " ";
    else for(auto node : res) cout << node << " ";

    return 0;
}
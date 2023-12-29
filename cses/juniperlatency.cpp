#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> to(n), from(n), weights(n);
    for(int i=0;i<n;i++) cin >> to[i];
    for(int i=0;i<n;i++) cin >> from[i]; 
    for(int i=0;i<n;i++) cin >> weights[i]; 
    vector<vector<pair<int, int> adj(n);
    for(int i=0;i<n;i++){
        int u = to[i], v = from[i], wt = weights[i];
        adj[u].push_back({v,wt});
    }
    return 0;
}
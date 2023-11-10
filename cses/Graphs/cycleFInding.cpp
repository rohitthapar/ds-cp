#include <bits/stdc++.h>
using namespace std;

// vector<int> res;
// bool dfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& inStack, int node) {
//     vis[node] = 1;
//     inStack[node] = 1;
//     for (auto it : adj[node]) {
//         if (!vis[it.first]) {
//             if (dfs(adj, vis, inStack, it.first)) {
//                 return true;
//             }
//         }
//         else if (inStack[it.first]) {
//             return true;
//         }
//     }
//     inStack[node] = 0;

//     return false;
// }
// bool hasCycle(vector<vector<pair<int, int>>>& adj, int n) {
//     vector<int> vis(n+1, 0);
//     vector<int> inStack(n+1, 0);
//     for (int i = 0; i < n+1; i++) {
//         if (!vis[i] && dfs(adj, vis, inStack, i)) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, int>> > adj(n+1);
//     for (int i = 0; i < m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({ v, w });
//     }
//     if (hasCycle(adj, n)) {
//         cout << "YES" << endl;
//     } else {
//         cout << "NO" << endl;
//     }
//     return 0;
// }

cout<<"PORN"
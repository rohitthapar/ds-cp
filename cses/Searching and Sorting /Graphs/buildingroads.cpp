#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int>>& roads) {
    vis[node] = 1;
    for (auto road : roads[node]) { 
        if (!vis[road]) dfs(road, vis, roads);
    }
}

void buildingRoad(int n, int m, vector<vector<int>>& roads) {
    vector<int> vis(n, 0);
    vector<int> r;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            r.push_back(i);
            dfs(i, vis, roads);
        }
    }
    cout << r.size() << endl;
    for (int i = 1; i < r.size(); i++) { 
        cout << r[i] << " ";
    }
}

int main() {
    int n, m; // cities, roads
    cin >> n >> m;
    vector<vector<int>> roads(n+1); 
    for (int i = 0; i < m; i++) {
        int to, from;
        cin >> to >> from;
        roads[to].push_back(from); 
        roads[from].push_back(to); 
    }
    buildingRoad(n, m, roads);
    return 0;
}

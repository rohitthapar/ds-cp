#include <bits/stdc++.h>
using namespace std;
class dsu {
public:
    vector<int> pt, sz;
    dsu(int n){
        pt.resize(n+1,0);
        sz.resize(n+1);
        for(int i=0;i<=n;i++){
            pt[i] = i; sz[i] = 0;
        }
    }
    int up(int node) { return (node == pt[node])? node : pt[node] = up(pt[node]); }
    void ubs(int u, int v){
        u = up(u), v = up(v);
        if(u == v) return;
        if(sz[u] < sz[v]){
            pt[u] = v; sz[v] += sz[u]; 
        } else {
            pt[v] = u; sz[u] += sz[v];
        }
    }
};
vector<int> solve(int n, vector<int> from, vector<int> to, vector<int> weight, vector<vector<int>> qu){
    dsu ds(n);
    int m = from.size();
    vector<int> andComp(n+1,INT_MAX);
    vector<int> res;
    for(int i=0;i<m;i++){
        int u = from[i], v = to[i], w = weight[i];
        if(ds.up(u) != ds.up(v)) {
            ds.ubs(u, v);
            if(andComp[ds.up(u)] != INT_MAX) andComp[ds.up(u)] &= w;
            else andComp[ds.up(u)] = w;

            if(andComp[ds.up(v)] != INT_MAX) andComp[ds.up(v)] &= w;
            else andComp[ds.up(v)] = w;
        }
    }
    for(auto q : qu){
        int u = ds.up(q[0]), v = ds.up(q[1]);
        if(u != v) res.push_back(-1);
        else res.push_back(andComp[u]);
    }
    return res;
}
int main(){
    int n = 5;
    vector<int> from = {3, 3, 2, 1};
    vector<int> to = {1, 2, 1, 4};
    vector<int> weight = {2, 3, 9, 1};
    vector<vector<int>> qu = {{4, 3}, {1, 5}};
    vector<int> res = solve(n, from, to, weight, qu);
    for(auto r : res) cout << r << " ";
    return 0;
}
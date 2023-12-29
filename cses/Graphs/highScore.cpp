#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll> 
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> gp;
    vector<int> dis(n+1, 1e9);
    dis[1] = 0; dis[0] = 0;

    for(int i=0;i<m;i++){
        int u, v, x; cin >> u >> v >> x;
        gp.push_back({u,v,x}); // from, to, cost
    }

    for(int i=0;i<n-1;i++){
        for(auto it : gp){
            int u = it[0], v = it[1], x = it[2];
            if(dis[u] != 1e9 && dis[u] + x < dis[v]){
                dis[v] = dis[u] + x;
            }
        }
    }


    
    // for(auto d : dis) cout << d << " ";
    // cout << endl;
    // for(auto it : gp){
    //     int u = it[0], v = it[1], x = it[2];
    //     if(dis[u] != 1e9 && dis[u] + x < dis[v]){
    //         dis[v] = dis[u] + x;
    //     }
    // }

    // cout << "after nth relaxation" << endl;
    // for(auto d : dis) cout << d << " ";
    return 0;
}
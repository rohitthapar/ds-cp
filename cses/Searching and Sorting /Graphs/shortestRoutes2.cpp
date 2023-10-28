#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9+7;
int main(){
	int  n, m, q;
	cin >> n >> m >> q;
	vector<vector<int >> edges;
	for(int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({a, b, w});
	}
	ll adj[n+1][n+1];
	for(int  i = 1; i <= n; i++) {
		for(int  j = 1; j <= n; j++) {
			adj[i][j] = LLONG_MAX;
			if(i == j)
				adj[i][j] = 0;
		}
	}
	for(auto e : edges) {
		int a = e[0], b = e[1];
        ll c = e[2];
		adj[a][b] = min(c, adj[a][b]);
		adj[b][a] = min(c, adj[a][b]);
	}
	for(int  i = 1; i <= n; i++) {
		for(int  j = 1; j <= n; j++) {
			for(int  k = 1; k <= n; k++) {
                if(adj[j][i]==LLONG_MAX||adj[i][k]==LLONG_MAX)continue;
				adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
			}
		}
	}
	while(q--) {
		int  a, b;
		cin >> a >> b;
		if(adj[a][b] == LLONG_MAX)
			cout << -1 << '\n';
		else
		cout << adj[a][b] << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int check(vector<vector<int>> &adj, int node, vector<int> &active, int n){
	for(auto it : adj[node]){
		if(it < node && active[it] == 0) return it;
	}
	return -1;
}
vector<int> recoverDeadPods(int n, vector<vector<int>> connections, vector<vector<int>> queries){
	vector<vector<int>> adj(n);
	int m = connections.size();
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// int q = queries.size();
	vector<pair<int, int>> qr(q);
	for(int i=0;i<queries.size();i++){
		int op = queries[i][0], id = queries[i][1];
		qr[i].first = op;
		qr[i].second = id;
	}
	vector<int> res;
	vector<int> active(n, 0);
	for(auto it : qr){
		int op = it.first, id = it.second;
		if(op == 2) active[id] = 1; 
		else if(op == 1){
			if(active[id] == 0) continue; 
			else if(active[id] != 0 and check(adj, id, active, n) != -1){
				res.push_back(check(adj, id, active, n));
			}
			else res.push_back(-1);
		}
	}
	return res;
}
int main(){
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> adj(n);
	// forming the graph
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// enter queries
	vector<pair<int, int>> qr(q);
	for(int i=0;i<q;i++){
		int op, id;
		cin >> op >> id;
		qr[i].first = op;
		qr[i].second = id;
	}
	vector<int> res;
	vector<int> active(n, 0); // 0 -> all are active
	// vector<int> vis(n, 0);
	for(auto it : qr){
		int op = it.first, id = it.second;
		if(op == 2) active[id] = 1; // make it inactive
		else if(op == 1){
			// if active[id] is active then it will write in db itself
			if(active[id] == 0) continue; 
			// if active[id] is not active but lower pod is active 
			else if(active[id] != 0 and check(adj, id, active, n) != -1){
				res.push_back(check(adj, id, active, n));
			}
			else res.push_back(-1);
			// if no lower pod is active 
		}
	}
	for(auto i : res) cout << i << " ";
	return 0;
}
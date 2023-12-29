// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back

// vector<int> path;
// int sn, en;

// bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
//     vis[node] = 1;
//     path.pb(node);
//     for(auto i : adj[node]){
//         if(!vis[i]){
//             if(dfs(i, node, adj, vis)) return true;
//         } 
//         if(i != parent){
//             sn = i;
//             en = parent;
//             return true;
//         }
//     } 
//     return false;
// }
// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n+1);
//     vector<int> vis(n+1,0);
//     for(int i=1;i<=m;i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].pb(v);
//         adj[v].pb(u);
//     }
//     bool flag = true;
//     for(int i=1;i<=n;i++){
//         if(!vis[i]) {
//             flag = dfs(i, -1, adj, vis);
//             if(!flag) break;
//         }
//     }

//     cout << "end ptr" << en+1 << " " << "start ptr" << sn+1 << endl;
//     if(flag){ 
//     } else cout << "IMPOSSIBLE" << endl;
//     return 0;
// }
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
 
int n, m;
int sv, ev;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
 
 
bool dfs(int u, int p)
{
	vis[u] = true;
	parent[u] = p;
	for(auto v: g[u])
	{
		if(v == p) continue;
		if(vis[v]) 
		{
			sv = v; 
			ev = u; 
			return true;
		} 
		if(!vis[v]) 
			if(dfs(v,u)) 
				return true;
	}
	return false;
}
 
 
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	parent.resize(n+1);
	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	if(!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	int tv = ev;
	vector<int> ans;
	ans.push_back(ev);
	while(tv != sv)
	{
		ans.push_back(parent[tv]);
		tv = parent[tv];
	}
	ans.push_back(ev);
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		cout << c << " ";
	}
 
}



class AuthenticationManager {
public:
    int ttl = 0;
    set<pair<int, string>> time_map;
    unordered_map<string, int> token_map;
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
    void clean(int currentTime) {
        while(!time_map.empty() && begin(time_map)->first <= currentTime) {
            token_map.erase(begin(time_map)->second);
            time_map.erase(begin(time_map));
        }
    }
    void generate(string tokenId, int currentTime) {
        token_map[tokenId] = currentTime + ttl;
        time_map.insert({currentTime + ttl, tokenId});
    }
    void renew(string tokenId, int currentTime) {
        clean(currentTime);
        auto it = token_map.find(tokenId);
        if (it != end(token_map)) {
            time_map.erase({it->second, it->first});
            it->second = currentTime + ttl;
            time_map.insert({currentTime + ttl, tokenId});
        }
    }
    int countUnexpiredTokens(int currentTime) {
        clean(currentTime);
        return token_map.size();
    }
};

def getUnexpiredTokens(time_to_live, queries):
    token_dict = {}
    result = []
    
    for query in queries:
        tokens = query.split()
        
        if tokens[0] == "generate":
            token_id = tokens[1]
            current_time = int(tokens[2])
            expiration_time = current_time + time_to_live
            token_dict[token_id] = expiration_time
        
        elif tokens[0] == "renew":
            token_id = tokens[1]
            current_time = int(tokens[2])
            if token_id in token_dict and token_dict[token_id] > current_time:
                token_dict[token_id] = current_time + time_to_live
        
        elif tokens[0] == "count":
            current_time = int(tokens[1])
            count = sum(1 for exp_time in token_dict.values() if exp_time > current_time)
            result.append(count)
    
    return result`
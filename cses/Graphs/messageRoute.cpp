# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
using namespace std;
 
int n,m;
vector <vector<int>> adList;
vector <bool> vis;
vector<int> p;
queue <int> q;
	
bool bfs(int start,vector<int>&path){
    p.assign(n,0);
    vis.assign(n,0);
    q.push(start);
    vis[start]=true;
    bool connect=false;
	while (!q.empty()){
		int v=q.front();
        if (v==n-1) {
            connect=true;
            break;
        }
		q.pop();
		for (int &u:adList[v]){
			if (vis[u]) continue;
			vis[u]=true;
			p[u]=v;
			q.push(u);
		}
	}
    if (!connect) return false;
    int tmp=n-1;
    while (tmp!=0){
        path.push_back(tmp);
        tmp=p[tmp];
    }
    reverse(all(path));
    return true;
}
int main(){
	cin>>n>>m;
	adList.assign(n,vector<int>());
    int x,y;
	for (int i=0;i<m;++i){
		cin>>x>>y;x--;y--;
		adList[x].push_back(y);
		adList[y].push_back(x);
	}
    vector<int> path;
    if (bfs(0,path)){
        cout<<path.size()+1<<'\n';
        cout<<1;
        for (int &v:path){
            cout<<' '<<v+1;
        }
        cout<<'\n';
    }
    else cout<<"IMPOSSIBLE\n";
	return 0;
}


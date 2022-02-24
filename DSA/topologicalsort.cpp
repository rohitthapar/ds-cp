// #include<iostream>
// #include<vector>
// #include<pair>

// using namespace std;
// int main(){
//     //input vertex and corresponding in-degree
//     <vector<pair<int,int>> vertex;
//     vector<int> vertex_name;
//     vector<int> vertex_value;
//     int n;
//     cin>>n;


//     for(int i=0;i<n;i++){
//         int v,u;
//         cin>>v>>u;
//         vertex_name.push_back(v);
//         vertex_value.push_back(u);
//         vertex.push_back(make_pair(vertex_name[i],vertex_value[i]));
//     }
//     int n = vertex_name.size();
//     for(int i=0;i<n;i++){
//         if(vertex[i].second == 0){

//         }
//     }

//     return 0;
// }

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    vector<int> InDeg (N,0);
	    for(int i=0;i<N;i++){
	        for(auto it : adj[i]){
	            InDeg[it]++;
	        }
	    }
	    for(int i=0;i<N;i++){
	        if(InDeg[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it : adj[node]){
	            InDeg[it]--;
	            if(InDeg[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
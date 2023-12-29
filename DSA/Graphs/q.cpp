#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            parent.resize(n+1,0);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = i;
            }
        }
        int findUltimateParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUltimateParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int upu = findUltimateParent(u);
            int upv = findUltimateParent(v);
            if(upu == upv) return;
            if(size[upu] < size[upv]){
                parent[upu] = upv;
                size[upv] = max(size[upv],size[upu]);
            } else {
                parent[upv] = upu;
                size[upu] = max(size[upu],size[upv]);
            }
        }
};

vector<long> networkSums(int c_nodes, vector<int> c_from, vector<int> c_to){
    DisjointSet ds(c_nodes+1);
    vector<long> time(c_nodes);
    for(int i=0;i<c_nodes;i++){
        int u = c_from[i];
        int v = c_to[i];
        int sum = 0;
        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            ds.unionBySize(u, v);
            ds.size[v] = 0;
            for(int j=0;j<c_nodes+1;j++){
                sum += ds.size[j];
            }
         } else {
            for(int j=0;j<c_nodes+1;j++){
                sum += ds.size[j];
            }
        }
        time[i] = (long)sum;
        
    }
    return time;
}

vector<int> getVisibleProfilesCount(int connection_nodes, vector<int> connection_from, vector<int> connection_to, vector<int> queries){
    DisjointSet ds(connection_nodes+1);
    int n = connection_from.size();
    for(int i=0;i<n;i++){
        int u = connection_from[i];
        int v = connection_to[i];
        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            ds.unionBySize(u, v);
        }
    }
    int m = queries.size();
    vector<int> res(m);
    for(int i=0;i<m;i++){
        int parent = ds.findUltimateParent(queries[i]);
        res[i] = ds.size[parent];
    }    
    return res;
}


int main(){
    vector<int> connection_from = {1,2,3,5};
    vector<int> connection_to = {2,3,4,6};
    vector<int> queries = {1,3,5,7};
    // vector<int> res = getVisibleProfilesCount(7, connection_from, connection_to, queries);
    vector<int> c_from = {1,2};
    vector<int> c_to = {2,1};
    vector<long> res = networkSums(2, c_from, c_to);

    for(int i=0;i<res.size();i++) cout << res[i] << " ";
    return 0;
}
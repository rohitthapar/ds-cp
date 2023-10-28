#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
        vector<int> parent, rank, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1,0);
            rank.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node){
            if(node == parent[node]) return node;
            return  parent[node] = findUltimateParent(parent[node]);
        }

        void findUnionByRank(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            if(ulp_u < ulp_v) {
                parent[ulp_u] = ulp_v;
            }
            else if(ulp_u > ulp_v) parent[ulp_v] = ulp_u;
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void findUnionBySize(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main(){
    int n;
    cin >> n;
    
    return 0;
}
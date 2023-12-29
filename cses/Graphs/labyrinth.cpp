#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pr;
typedef long long ll;
const int dr[4] = {1,0,-1,0};
const int dc[4] = {0,-1,0,1}; 

bool isValid(int row, int col, int n, int m){
    return row >= 0 and row < n and col >= 0 and col < m;
}

void dfs(int row, int col, int n, int m, vector<vector<char>>& mat, vector<vector<int>>& vis){
    vis[row][col] = 1;
    for(int i=0;i<4;i++){
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && mat[nrow][ncol] == '.'){
            dfs(nrow, ncol, n, m, mat, vis);
        }
    }
}

void labyrinth(int n, int m, vector<vector<char>>& mat, int ra, int ca, int rb, int cb){
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({1, {ra, rb}});
    vis[ra][rb] = 1;
    while(!pq.empty()){
        auto top = pq.top();
        int wt = top.first;
        int row = top.second.first;
        int col = top.second.second;
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int ra, ca, rb, cb;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin >> a;
            mat[i][j] = a;
            if(mat[i][j] == 'A') {
                ra = i;
                rc = j;
            } 
            if(mat[i][j] == 'B') {
                rb = i;
                cb = j;
            }
        }
    }
    labyrinth(n, m, mat, ra, ca, rb, cb);
    return 0;
}


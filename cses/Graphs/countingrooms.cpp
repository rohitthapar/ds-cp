#include<bits/stdc++.h>
using namespace std;

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

int countRooms(int n, int m, vector<vector<char>>& mat){
    vector<vector<int>> vis(n, vector<int>(m,0));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j] == '.'){
                dfs(i, j, n, m, mat, vis);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin >> a;
            mat[i][j] = a;
        }
    }
    int count = countRooms(n, m, mat);
    cout << count << " ";
    return 0;
}
// bfs solution having neighbours in all 8 directions
// leetcode checks for only 4 directions
class Solution{
private:
    void bfs(int row, int col, vector<vector<int>>& vis, 
             vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            //check neighbours
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m /*validity*/
                      && grid[nr][nc] == '1' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count = 0;
        for(int row = 0;row < n;row++){
            for(int col = 0;col < m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};
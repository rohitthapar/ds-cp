// https://leetcode.com/problems/maximal-square/
#include<iostream>
#include<vector>
using namespace std;
int maximalSquare(vector<vector<int>> v,int n ,int m){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(v[i][j] == 0){
                d[i][j] = 0;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,-1));
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    
    return 0;
}

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
     
//         int m = size(M), n = size(M[0]), ans = 0;
//         vector<vector<int>> dp(m+1, vector<int>(n+1));
//         for(int i = m-1; ~i; i--)
//             for(int j = n-1; ~j; j--) 
//                 dp[i][j] = (M[i][j] == '1' ? 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) : 0),
//                 ans = max(ans, dp[i][j]);

//         return ans * ans;
//     }
// };
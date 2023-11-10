#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    bool isvalid(int x , int y , int n){
        return x>=1 && y>=1 && x<=n && y<=n;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int path=INT_MAX;
        int dx[]={2,2,-2,-2,1,-1,1,-1};
        int dy[]={1,-1,1,-1,2,2,-2,-2};
        int x=KnightPos[0];
        int y=KnightPos[1];
        int xd=TargetPos[0];
        int yd=TargetPos[1];
        
        vector<vector<bool>>visited(N+1,vector<bool>(N+1,false));
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{x,y},0});
        visited[x][y]=true;
        while(!q.empty())
        {
            auto it=q.front();
            int i=it.first.first;
            int j=it.first.second;
            int step=it.second;
            q.pop();
            if(i==xd && j==yd)
            {
                return step;
            }
            
            for(int k=0 ; k<8 ; k++)
            {
                int newx=i+dx[k];
                int newy=j+dy[k];
                
                if(isvalid(newx,newy,N) && visited[newx][newy]==false)
                {
                    visited[newx][newy]=true;
                    q.push({{newx,newy},step+1});
                }
            }
        }
        return -1;
    }
};

bool isvalid(int x , int y , int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
int minMoves(int n, int x, int y, int xd, int yd){
    	int path=INT_MAX;
        int dx[]={2,2,-2,-2,1,-1,1,-1};
        int dy[]={1,-1,1,-1,2,2,-2,-2};
        vector<vector<bool>>visited(n+1,vector<bool>(n+1,false));
        queue<pair<pair<int,int>,int>>q;
        q.push({{x,y},0});
        visited[x][y]=true;
        while(!q.empty())
        {
            auto it=q.front();
            int i=it.first.first;
            int j=it.first.second;
            int step=it.second;
            q.pop();
            if(i==xd && j==yd)
            {
                return step;
            }
            
            for(int k=0 ; k<8 ; k++){
                int newx=i+dx[k];
                int newy=j+dy[k];
                if(isvalid(newx,newy,n) && visited[newx][newy]==false)
                {
                    visited[newx][newy]=true;
                    q.push({{newx,newy},step+1});
                }
            }
        }
        return -1;
}

//{ Driver Code Starts.
int main(){
    int n;
    cin >> n;
    int x, y, xd, yd;
    cin >> x >> y >> xd >> yd;
    int res = minMoves(n, x, y, xd, yd);
    cout << res << " ";
	return 0;
}
// } Driver Code Ends



long getMaximumPower(vector<int>& power) {
    int n = power.size();
    sort(power.begin(), power.end());
    vector<long> dp(n, 0);
    vector<long> used(n, 0);
    vector<long> not_used(n, 0);
    dp[0] = (long)power[0];
    used[0] = (long)power[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(not_used[i - 1] + (long)power[i], dp[i - 1]);
        used[i] = not_used[i - 1] + (long)power[i];
        not_used[i] = max(used[i - 1], not_used[i - 1]);
    }
    return dp[n - 1];
}
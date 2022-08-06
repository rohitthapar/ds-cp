//  https://www.codingninjas.com/codestudio/problems/frog-jump_3621012


// recursive solution
#include<bits/stdc++.h>
int f(int n, vector<int> &h){
    if(n == 0) return 0;
    int l = f(n-1,h) + abs(h[n] - h[n-1]);
    int r = INT_MAX;
    if(n > 1) r = f(n-2,h) + abs(h[n] - h[n-2]);
    return min(l,r);
}
int frogJump(int n, vector<int> &h)
{
    // Write your code here.
   return f(n-1,h);
}

// memoization -> Top Down Approach

#include<bits/stdc++.h>
int f(int n, vector<int> &h, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int l = f(n-1,h,dp) + abs(h[n] - h[n-1]);
    int r = INT_MAX;
    if(n > 1) r = f(n-2,h,dp) + abs(h[n] - h[n-2]);
    return dp[n] = min(l,r);
}
int frogJump(int n, vector<int> &h)
{
    vector<int> dp(n+1, -1);
   return f(n-1,h,dp);
}

// Tabulation -> Bottom Up Approach

#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}

// Space optimisation

#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}
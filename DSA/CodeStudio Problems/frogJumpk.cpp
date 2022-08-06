// https://atcoder.jp/contests/dp/tasks/dp_b

// recursive solution

#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
int f(int idx , int k , vector<int> &h){
    if(idx == 0) return 0;
    int minSteps = INT_MAX;
    for(int j = 1;j<=k;j++){
        if(idx - j >= 0){
            int jump = f(idx - j, k,h) + abs(h[idx] - h[idx-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}
int frogJump(int n,int k,vector<int> &h){
    return f(n-1,k,h);
}
// memoisation -> TopDown Approach
int f(int idx, int k, vector<int> &h, vector<int> &dp){
    if(idx == 0) return 0;
    int minSteps = INT_MAX;
    if(dp[idx] != -1) return dp[idx];
    for(int j = 1;j<=k;j++){
        if(idx - j >= 0){
            int jump = f(idx - j,k,h,dp) + abs(h[idx] - h[idx-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[idx] = minSteps;
}
int frogJumps(int n,int k, vector<int> &h){
    vector<int>dp(n+1,-1);
    return f(n-1,k,h,dp);
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    cout << frogJumps(n,k,h) << endl;
    return 0;
}

// Tabulation -> Bottom UP
#include <bits/stdc++.h>
using namespace std;
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n, height, dp, k);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}
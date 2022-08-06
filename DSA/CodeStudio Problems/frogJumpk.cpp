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
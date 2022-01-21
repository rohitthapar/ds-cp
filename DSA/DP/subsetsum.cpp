#include<iostream>
#include<cstring>
using namespace std;
int dp[102][1002];
//knapsack recursive 

// //knapsack memoization
int knapsack(int wt[], int val[], int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n-1]<=W){
        return dp[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else return knapsack(wt,val,W,n-1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];

    }
    cout<<knapsack(wt,val,w,n)<<endl;    

    return 0;
}
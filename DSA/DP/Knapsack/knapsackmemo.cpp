#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int dp[102][1002];
int knapsack(int wt[],int val[],int w, int n){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else return knapsack(wt,val,w,n-1);
}
int main(){
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];

    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(wt,val,w,n)<<endl;    

    return 0;
}
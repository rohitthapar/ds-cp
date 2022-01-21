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
//converting knapsack to subset sum problem 
// recursive code -> subset sum problem
bool subsetSum(int arr[], int n, int S){
    if(n==0 && S==0){
        //base condition 
        //if array is zero then the sum will also be zero
        return true;
    }
    if(n==0 && S!=0){
        return false;
    }

    if(arr[n-1]<=S){
        return (subsetSum(arr,n-1,S-arr[n-1]) || subsetSum(arr,n-1,S));
    }
    else return subsetSum(arr,n-1,S);
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
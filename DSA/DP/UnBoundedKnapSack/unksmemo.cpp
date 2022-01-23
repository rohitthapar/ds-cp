#include<iostream>
#include<cstring>
using namespace std;
int dp[102][1002];
int UNknapsack(int wt[],int val[],int w, int n){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]>w){
        return UNknapsack(wt,val,w,n-1);
    }
    else return dp[n][w] = max(val[n-1]+UNknapsack(wt,val,w-wt[n-1],n),UNknapsack(wt,val,w,n-1));
}
int main(){
    int n,w;
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];

    }
    for(int i=0;i<n;i++){
        cin>>val[i];

    }
    cout<<UNknapsack(wt,val,w,n)<<endl;    

    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int dp[102][1002];
int knapsack(int wt[],int val[],int w,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
        }
    }

    //choice diagram
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]>w){
                dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
        }
    }
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
//Coin change minimum number of ways
// dynamic programming 
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int dp[102][1002];
int countSum(int arr[],int n,int s){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(j == 0){
                dp[i][j] = 0;
            }
            if(i == 0){
                dp[i][j] = INT_MAX-1;
            }
        }
    }
    //second initialisation
    int j=1;
    for(int i=1;j<n+1;j++){
        if(j%arr[0] == 0){
            dp[i][j] = j/arr[0];
        }
        else dp[i][j] = INT_MAX-1;
    }
    //choice diagram
    for(int i=2;i<n+1;i++){
        for(int j=1;j<s+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-arr[i-1]],dp[i-1][j]);
            }
            else return dp[i-1][j];
        }
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countSum(arr,n,s)<<endl;
    return 0;
}
// 3
// 5
// 1 2 3 
// 2 

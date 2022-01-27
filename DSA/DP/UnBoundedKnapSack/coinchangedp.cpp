#include<iostream>
#include<cstring>
const int MOD = (int) 1e9 + 7;
using namespace std;
int dp[102][1002];
int countSum(int arr[],int n,int s){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
        }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<s+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        } 
    }
    return dp[n][s] % MOD;

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
// 5
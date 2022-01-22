#include<iostream>
#include<cstring>
using namespace std;

int dp[102][1002];
int countSum(int arr[],int n,int sum){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
            }
        }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];

    }
int main(){
     memset(dp,-1,sizeof(dp));
    int n,diff;
    int sum = 0;
    cin>>n>>diff;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum = sum + arr[i];
    }
    int s = (sum + diff)/2;
    cout<<countSum(arr,n,s)<<endl;
    return 0;
}
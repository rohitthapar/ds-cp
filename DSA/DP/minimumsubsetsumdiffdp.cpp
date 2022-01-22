#include<iostream>
#include<cstring>
using namespace std;
int dp[102][1002];
int findMin(int arr[],int n,int c_sum,int sum){
    //base condition -> initialisation
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
                dp[i][j]= min(dp[i-1][j],dp[i-1][j-arr[i-1]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int findSum(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum +arr[i];
    }
    return findMin(arr,n,0,sum);
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findSum(arr,n)<<endl;
    return 0;
}
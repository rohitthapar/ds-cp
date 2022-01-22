#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//recursive code ---> memoization
int dp[102][1002];
int findMin(int arr[],int n,int c_sum,int sum){
    if(n == 0){
        return abs(sum - c_sum - c_sum);
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    dp[n][sum] = min(findMin(arr,n-1,c_sum+arr[n-1],sum),findMin(arr,n-1,c_sum,sum));
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
    memset(dp,-1,sizeof(dp));
    int n,range = 0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // range = range + arr[i];
    }
    cout<<findSum(arr,n)<<endl;
    // cout<<subsetSum(arr,n,range)<<endl;
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
//recursion code
int dp[102][1002];
int countSum(int arr[],int n,int sum){
    if(sum == 0){
        return 1;
    }
    // int n = sizeof(arr);
    if(n == 0){
        return 0;
    }
    if(dp[n-1][sum]!=-1){
        return dp[n-1][sum];
    }
    if(arr[n-1]<=sum){
        return dp[n-1][sum] = countSum(arr,n-1,sum-arr[n-1]) + countSum(arr,n-1,sum);
    }
    else return countSum(arr,n-1,sum);

}
//memoization of the recursive code
int main(){
    memset(dp,-1,sizeof(dp));
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countSum(arr,n,sum)<<endl;
    return 0;
}
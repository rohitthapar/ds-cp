//Coin change minimum number of ways

// memoisation

#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int dp[102][1002];
int countSum(int arr[],int n,int s){
    if(n == 0){
        return INT_MAX-1;
    }
    if(s == 0){
        return 0;
    }
    if(dp[n][s]!=-1){
        return dp[n][s];
    }
    if(arr[n-1]<=s){
        return dp[n][s] = min(1+countSum(arr,n,s-arr[n-1]),countSum(arr,n-1,s));
    }
    else return countSum(arr,n-1,s);
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

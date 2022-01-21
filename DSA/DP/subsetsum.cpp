#include<iostream>
#include<cstring>
using namespace std;
int dp[102][1002];
//converting knapsack to subset sum problem 
// recursive code -> subset sum problem
bool subsetSum(int arr[], int n, int S){
    if(n==0 && S==0){
        return true;
    }
    if(n==0 && S!=0){
        return false;
    }

    if(arr[n-1]<=S){
        return subsetSum(arr,n-1,S-arr[n-1]) || subsetSum(arr,n-1,S);
    }
    else return subsetSum(arr,n-1,S);
}
// memoization of subset sum code problem
bool subsetSum_m(int arr[], int n, int S){
    if(S==0){
        //base condition 
        //if array is zero then the sum will also be zero
        return true;
    }
    if(n==0){
        return false;
    }
    if(dp[n][S]!=false){
        return dp[n][S];
    }

    if(arr[n-1]<=S){
        return dp[n][S]=(subsetSum(arr,n-1,S-arr[n-1]) || subsetSum(arr,n-1,S));
    }
    else return subsetSum(arr,n-1,S);
}

int main(){
    memset(dp,-1,sizeof(dp));
    // int n,w;
    // cin>>n>>w;
    // int wt[n],val[n];
    // for(int i=0;i<n;i++){
    //     cin>>wt[i]>>val[i];

    // }
    // cout<<knapsack(wt,val,w,n)<<endl;    
    int n,S;
    cin>>n>>S;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subsetSum(arr,n,S)<<endl;
    return 0;
}
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int dp[102][1002];
int minCost(int arr[],int i ,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = minCost(arr,i,k) + minCost(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp < mn){
            mn = temp;
        }
    }
    return dp[i][j] = mn;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minCost(arr,1,n-1)<<endl;
    return 0;
}
//40 20 30 10 30
//26000

//10 20 30 40 30 
//30000

//10 20 30
//6000
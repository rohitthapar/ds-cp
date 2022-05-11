#include<iostream>
// #include<bits/stdc+++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[5][n];
    for(int i=0;i<5;i++){
        dp[0][i] = 1;
    }
    for(int i=0;i<n;i++){
        dp[i][4] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=3;j>=0;j--){
            dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int sum = 0;
    for(int i=0;i<5;i++){
        sum = sum + dp[n-1][i];
    }
    cout<<sum;
    return 0;
}

//lexicographically sorted 
//longest repeating sub sequence dynamic programming solution
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int dp[102][1002];
int countLCS(string x,string y,int n,int m){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1] && i!=j){
                dp[i][j] = 1+dp[i-1][j-1]; 
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main(){
    memset(dp,-1,sizeof(dp));
    string x;
    cin>>x;
    int n = x.length();
    cout<<countLCS(x,x,n,n)<<endl;
    return 0;
}
// aabebcdd
//3
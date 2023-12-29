#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int dp[102][1002];
int countLCS(string x,string y,int n,int m){
    // if(n == 0 || m == 0){
    //     return 0;
    // }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1]; 
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
    // if(dp[n][m] != -1){
    //     return dp[n][m];
    // }
    // if(x[n-1] == y[m-1]){
    //     return dp[n][m] = 1+countLCS(x,y,n-1,m-1);
    // }
    // else return dp[n][m] = max(countLCS(x,y,n-1,m),countLCS(x,y,n,m-1));
}
int main(){
    memset(dp,-1,sizeof(dp));
    string x;
    string y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    cout<<countLCS(x,y,n,m)<<endl;
    return 0;
}
//abcdgh abedfhr
//4

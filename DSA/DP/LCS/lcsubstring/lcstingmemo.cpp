// //giving wrong answer
// #include<iostream>
// #include<string.h>
// #include<cstring>
// using namespace std;
// int dp[102][1002];
// int countLcstring(string x,string y,int n,int m,int count){
//     if(n == 0 || m == 0){
//         return count;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
//     if(x[n-1] == y[m-1]){
//         return  dp[n][m] = countLcstring(x,y,n-1,m-1,count+1);
//     }
//     else return  dp[n][m] = max(count,max(countLcstring(x,y,n-1,m,0),countLcstring(x,y,n,m-1,0)));
// }
// int main(){
//     memset(dp,-1,sizeof(dp));
//     string x;
//     string y;
//     cin>>x>>y;
//     int n = x.length();
//     int m = y.length();
//     int count;
//     cout<<countLcstring(x,y,n,m,0)<<endl;
//     return 0;
// }
// //abcdgh abedfhr
// //4

#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int dp[102][1002];
int ans;
int countLcstring(string x,string y,int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    countLcstring(x,y,n-1,m);
    countLcstring(x,y,n,m-1);

    if(x[n-1] == y[m-1]){
        dp[n][m] = countLcstring(x,y,n-1,m-1) + 1;
        ans = max(ans, dp[n][m]);
        return dp[n][m];
    }
    
    return  dp[n][m] = 0;
}
int main(){
    memset(dp,-1,sizeof(dp));
    ans = 0;
    string x;
    string y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    int count;
    countLcstring(x,y,n,m);
    cout<<ans<<endl;
    return 0;
}
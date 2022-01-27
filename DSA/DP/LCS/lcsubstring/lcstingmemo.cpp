//giving wrong answer
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int dp[102][1002];
int countLcstring(string x,string y,int n,int m,int count){
    if(n == 0 || m == 0){
        return count;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(x[n-1] == y[m-1]){
        return  dp[n][m] = countLcstring(x,y,n-1,m-1,count+1);
    }
    else return  dp[n][m] = max(count,max(countLcstring(x,y,n-1,m,0),countLcstring(x,y,n,m-1,0)));
}
int main(){
    memset(dp,-1,sizeof(dp));
    string x;
    string y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    int count;
    cout<<countLcstring(x,y,n,m,0)<<endl;
    return 0;
}
//abcdgh abedfhr
//4
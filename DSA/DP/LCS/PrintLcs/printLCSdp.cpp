#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
string s;
int dp[102][1002];
string countLCS(string x,string y,int n,int m){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }
        }
    }
    int i = n,j = m;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else i--;
    }
    reverse(s.begin(),s.end());
    return s;

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
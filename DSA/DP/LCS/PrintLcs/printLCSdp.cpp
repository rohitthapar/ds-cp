#include<iostream>
#include<string.h>
#include<cstring>
#include<vector>
using namespace std;
vector<char> s;
int dp[102][1002];
void countLCS(string x,string y,int n,int m){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0 || j ==0){
                dp[i][j] = 0;
            }
            else if (x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = n,j = m;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            // cout<<s[i];
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else i--;
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }

}
int main(){
    memset(dp,-1,sizeof(dp));
    string x;
    string y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    countLCS(x,y,n,m);
    return 0;
}
//abcdgh abedfhr
//abdh
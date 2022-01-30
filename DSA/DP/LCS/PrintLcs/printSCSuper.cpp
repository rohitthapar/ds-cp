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
            s.push_back(y[j-1]);
            j--;
        }
        else if(dp[i][j-1]<dp[i-1][j]){
            s.push_back(x[i-1]);
            i--;
        }
    }
    while(i>0){
            s.push_back(x[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(y[j-1]);
            j--;
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
// class Solution {
// public:
//     string shortestCommonSupersequence(string X, string Y) {
//        int n=X.size(), m=Y.size();
// 	int t[n+1][m+1];
// 	for(int i=0;i<=n;i++)
// 		for(int j=0;j<=m;j++){
// 			if(i==0||j==0)
// 				t[i][j]=0;
// 		}
		
// 	for(int i=1;i<=n;i++)
// 		for(int j=1;j<=m;j++){
// 			if(X[i-1]==Y[j-1])
// 				t[i][j]= 1+t[i-1][j-1];
// 			else
// 				t[i][j]= max(t[i-1][j],t[i][j-1]);
// 		}
		
// 	int i=n,j=m;
// 	string s;
// 	while(i>0&&j>0){
// 		if(X[i-1]==Y[j-1]){
// 			s += X[i - 1];
// 			i--, j--;
// 		}
// 		else
// 		{
// 			if(t[i][j-1]>t[i-1][j]){
// 				s += Y[j - 1];
// 				j--;
// 			}
// 			else{
// 				s += X[i - 1];
// 				i--;
// 			}
// 		}
// 	}
	
// 	while(i>0){
// 		s.push_back(X[i-1]);
// 		i--;
// 	}
	
// 	while(j>0){
// 		s.push_back(Y[j-1]);
// 		j--;
// 	}
// 	reverse(s.begin(), s.end());
// 	return s; 
//     }
// };
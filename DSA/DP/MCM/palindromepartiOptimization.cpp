//palindrome partitioning -> optimisation 
#include<iostream>
#include<climits>
#include<string>
#include<climits>
using namespace std;
int static dp[102][1002];
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}
int palindromeP(string arr,int i ,int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(arr,i,j) == true){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int mn = INT_MAX,temp,left,right;
    for(int k=i;k<=j-1;k++){
        // temp = palindromeP(arr,i,k) + palindromeP(arr,k+1,j) + 1;
        if(dp[i][k]!=-1){
            left = dp[i][k];
        }
        else {
            left = palindromeP(arr,i,k);
            dp[i][k] = left;
        }
        if(dp[k+1][j]!=-1){
            right = dp[k+1][j];
        }
        else {
            right = palindromeP(arr,k+1,j);
            dp[k+1][j] = right;
        }
        temp = 1+left+right;
        mn = min(mn,temp);
        // if(temp < mn){
        //     mn = temp;
        // }
    }
    return dp[i][j] = mn;
}
int main(){
    memset(dp,-1,sizeof(dp));
    string x;
    cin>>x;
    int n = x.length();
    cout<<palindromeP(x,0,n-1)<<endl;
    return 0;
}

// Input : str = “geek” 
// Output : 2 
// We need to make minimum 2 cuts, i.e., “g ee k”
// Input : str = “aaaa” 
// Output : 0 
// The string is already a palindrome.
// Input : str = “abcde” 
// Output : 4

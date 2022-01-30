//palindrome partitioning
#include<iostream>
#include<climits>
#include<string.h>
using namespace std;
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
    int mn = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = palindromeP(arr,i,k) + palindromeP(arr,k+1,j) + 1;
        if(temp < mn){
            mn = temp;
        }
    }
    return mn;
}
int main(){
    string x;
    cin>>x;
    int n = x.length();
    cout<<palindromeP(x,1,n-1)<<endl;
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
// Input : str = “abbac” 
// Output : 1 
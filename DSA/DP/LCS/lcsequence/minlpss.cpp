//minimum number of deletions required to make a string palindrome
#include<iostream>
#include<string.h>
using namespace std;
int countLCS(string x,string y,int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1+countLCS(x,y,n-1,m-1);
    }
    else return max(countLCS(x,y,n-1,m),countLCS(x,y,n,m-1));
}
string reverse(string &x){
    int n = x.length();
    for (int i = 0; i < n / 2; i++){
        swap(x[i], x[n - i - 1]);
    }
    return x;
}

int main(){
    string x;
    cin>>x;
    int n = x.length();
    int count = countLCS(x,reverse(x),n,n);
    cout<< n - count <<endl;
    return 0;
}
// agbcba
// 1
// aebcbda
// 2
// geeksforgeeks
// 8
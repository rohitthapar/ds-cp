#include<iostream>
#include<string>
using namespace std;
int decodeWays(string s,int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(s[0] == 0){
        return 0; //invalid string
    }
    int res = 0;
    if(s[n-1]<=26 && s[n-1]>=1){
        return 1+decodeWays(s,n-1);
    }
    else return decodeWays(s,n);
    // return res;
}
int main(){
    string s;
    cin>>s;
    int n = s.length();
    cout<<decodeWays(s,n);
}
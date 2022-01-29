//longest repeating subsequence recursion
#include<iostream>
#include<string.h>
using namespace std;
int countRSS(string x,string y,int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(x[n-1] == y[m-1] && n-1!=m-1){
        return 1+countRSS(x,y,n-1,m-1);
    }
    else return max(countRSS(x,y,n,m-1),countRSS(x,y,n-1,m));
}
int main(){
    string x;
    cin>>x;
    int n = x.length();
    cout<<countRSS(x,x,n,n)<<endl;
    return 0;
}
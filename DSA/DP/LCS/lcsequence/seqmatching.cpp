//sequence pattern matching using recursion
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
bool seqM(string x,string y){
    int n = x.length();
    int m = y.length();
    int count = countLCS(x,y,n,m);
    if(count == n){
        return true;
    }
    else return false;
}
int main(){
    string x;
    string y;
    cin>>x>>y;
    if(seqM(x,y) == 1){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;
    return 0;
}
//axy adxcpy
//true
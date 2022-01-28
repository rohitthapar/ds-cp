//minimum nnumber of insertion and deletion to make a string a to b 
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
int main(){
    string x;
    string y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    int count = countLCS(x,y,n,m);
    cout<<"Ins->"<<m-count<<endl;
    cout<<"Del->"<<n-count<<endl;
    return 0;
}
//heap pea
//Ins->1 Del->2
//similar code of lcs for memoized and dp
#include<iostream>
#include<string.h>
using namespace std;

string s;
string printLCS(string x,string y,int n,int m){
    if(n == 0 || m == 0){
        return NULL;
    }
    if(x[n-1] == y[m-1]){
        s.push_back(x[n-1]);
        return printLCS(x,y,n-1,m-1);
    }
    else return max(printLCS(x,y,n-1,m),printLCS(x,y,n,m-1));

    reverse(s.begin(),s.end());
    return s;

}
int main(){
    string x;
    string y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    cout<<printLCS(x,y,n,m)<<endl;
    return 0;
}
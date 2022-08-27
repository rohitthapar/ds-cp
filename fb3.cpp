#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void solve(int t){
    int r,c;
    cin>>r>>c;
    vector<<vector<char>> m(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    if(r == 1 or c == 1)
    cout<<"Case #"<<t<<":"<<" Impossible"<<endl;

    

}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<t+1;i++){
        solve(i);
    }
 return 0;
}
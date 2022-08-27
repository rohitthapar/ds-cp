#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void solve(int t){
    int n,k;
    cin>>n>>k;
    int flag = 0;
    vector<int> s(n);
    map<int, int> mp; 
    for(int i=0;i<n;i++){
        cin>>s[i];
        mp[s[i]]++;
    }
    if(n >= 2*k){
        // flag = 1;
        cout<<"Case #"<<t<<":"<<" NO"<<endl;
        return;
    }
    for(auto it : mp){
        if(it.second > 2){
            cout<<"Case #"<<t<<":"<<" NO"<<endl;
            return;
        }
    }
    cout<<"Case #"<<t<<":"<<" YES"<<endl;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i);
    }
 return 0;
}
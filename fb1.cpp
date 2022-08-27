#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

bool check(string s){
    for(int i = 0;i<s.size();i++){
        if(s[i] != s[0]) return false;    
        }
    return true;
}
void solve(){
    string s;
    cin>>s;
    priority_queue<pair<int,char>> pq;
    if(check(s) == true){
        cout<<s.size()-1<<endl;
    }
    unordered_map<char, int> mp;
    for(auto i : s){
        mp[i]++;
    }
    
    for(auto i : mp){
        pq.push({i.second,i.first});
    }

}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
 return 0;
}
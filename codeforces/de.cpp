#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void solve(){
        string a;
        cin>>a;
        int n = a.size();
        int count = 0;
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        int np;
        cin>>np;
        vector<string> s(np);
        for(int i=0;i<np;i++) cin>>s[i];
        
        for(int i=0;i<np;i++){
            unordered_map<char,int> mp2 = mp;
            for(int j=0;j<s[i].size();i++){
                mp2[s[i][j]]--;
            }
            for(auto itr : mp2) {
                if(itr.second < 0) break;
                else count++;
                }
            mp2.clear();
        }
        cout<<count;

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
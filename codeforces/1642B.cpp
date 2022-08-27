#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void solve(){
        int n;
        cin>>n;
        vector<int> p(n);
        set<int> s;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            cin>>p[i];
            mp[p[i]]++;
            s.insert(p[i]);
        }
        int cnt = s.size();
        int c_cnt = cnt;
        for(int k = 1;k <= n;k++){
            cout<<max(k,c_cnt)<<" ";
        }
        return;
    }
int main()
{
    int t;
    cin>>t;
    while(t--){
    solve();
    cout<<"\n";
    }
return 0;
}
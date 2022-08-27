#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void solve(){
        int n;
        cin>>n;
        vector<int> nu(n);
        for(int i=0;i<n;i++) cin>>nu[i];
        sort(nu.begin(),nu.end());
        int x = (nu[n-1] - nu[0]) + (nu[n-2] - nu[1]);
        cout<<x<<endl;
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
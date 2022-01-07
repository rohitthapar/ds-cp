#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
int main(){
    ll t;
    cin>>t;
    vector<int>diff_max;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll w[n];
        for(ll i=0;i<n;i++){
            cin>>w[i];
        }
        sort(w,w+n);
        ll sum_s=0, sum_c=0;
        for(ll i=0;i<k;i++){
            sum_s = sum_s + w[i];
        }
        for(ll i=k;i<n;i++){
            sum_c = sum_c + w[i];
        }
        ll max_diff = sum_c - sum_s;
        diff_max.push_back(max_diff);
    }
    ll size = diff_max.size();
    for(ll i=0;i<size;i++){
        cout<<diff_max[i]<<endl;
    }
    return 0;
}
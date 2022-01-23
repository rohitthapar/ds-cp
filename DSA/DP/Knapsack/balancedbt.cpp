#include<iostream>
typedef long long ll;
using namespace std;
//recursion
ll balancedbt(ll h){
    //base case
    if(h<=1){
        return 1;
    }
    ll x = balancedbt(h-1);
    ll y = balancedbt(h-2);
    ll ans = x*x + 2*x*y;
    return ans;
}
//memoization
ll balancedbt_m(ll h,int *ans){
    if(h<=1){
        ans[h] = 1;
        return 1;
    }
    if(ans[h-1]==0){
        ans[h-1] = balancedbt_m(h-1,ans);
    }
    if(ans[h-2]==0){
        ans[h-2] = balancedbt_m(h-2,ans);
    }
    ans[h] = ans[h-1]*ans[h-1] + 2*ans[h-1]*ans[h-2];
    return ans[h];
}

ll balancedbt_m(ll h){
    int *ans = new int[h+1]{};
    return balancedbt_m(h,ans);
}
//dp
ll balancedbt_dp(ll h){
    int *ans = new int[h+1]{};
    ans[0] = 1;
    ans[1] = 1;
    for(ll i = 2;i<=h;i++){
        ans[i]=ans[i-1]*ans[i-1]+2*ans[i-1]*ans[i-2];
    }
    ll res = ans[h];
    delete [] ans;
    return res;
}
int main(){
    ll h;
    cin>>h;
    cout<<balancedbt_dp(h)<<endl;
    return 0;
}
// taking mod

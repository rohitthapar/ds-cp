#include<iostream>
typedef long long ll;
using namespace std;
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
int main(){
    ll h;
    cin>>h;
    cout<<balancedbt(h)<<endl;
    return 0;
}
// taking mod

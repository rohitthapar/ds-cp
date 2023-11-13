#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
using namespace std;
int main(){
    ll n, m; cin >> n >> m;
    vector<vector<pr>> gp(n+1);
    // ll mx = ll_MIN, res = 0;
    ll source = 1;
    priority_queue<pair<ll, pr>, vector<pair<ll, pr>>, greater<pair<ll, pr>>> pq;
    vector<ll> disTo(n+1, LONG_MAX);  // without coupon
    vector<ll> wdDisTo(n+1, LONG_MAX);  // with coupon

    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        gp[a].push_back({b, c}); // from, to , cost
    }

    disTo[source] = wdDisTo[source] = 0;
    pq.push({0, {source, 0}}); // distance, place, flag
    while(!pq.empty()){
        ll dis = pq.top().first;
        ll src = pq.top().second.first;
        ll flag = pq.top().second.second;
        pq.pop();
        if(flag == 1) if(wdDisTo[src] < dis) continue;
        if(flag == 0) if(disTo[src] < dis) continue;
        for(auto it : gp[src]){
            ll des = it.first;
            ll cost = it.second;
            if(flag == 0){
                if(disTo[des] > cost + dis){
                    disTo[des] = cost + dis;
                    pq.push({disTo[des], {des, 0}});
                }
                if(wdDisTo[des] > (floor(cost/2) + dis)){
                    wdDisTo[des] = (floor(cost/2) + dis);
                    pq.push({wdDisTo[des] , {des, 1}});
                }
            }
            if(flag == 1){
                if(wdDisTo[des] > cost + dis){
                    wdDisTo[des] = cost + dis;
                    pq.push({wdDisTo[des], {des, 1}});
                }
            }
        }
    }
    cout << wdDisTo[n] << " ";
    // for(auto d : disTo) cout << d << " ";
    return 0;
}
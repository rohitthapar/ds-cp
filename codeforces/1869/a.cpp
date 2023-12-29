#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int k = a[0];
    for(int i=1;i<n;i++) k ^= a[i];
    cout << k << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    long long s = 0, r;
    for(int i=0;i<n-1;i++){
        cin >> r;
        s += r;
    }
    cout << (n*(n+1))/2 - s << " ";
    return 0;
}
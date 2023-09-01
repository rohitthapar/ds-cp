#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> server(n, vector<int>(2)); 
    for (int i = 0; i < n; i++) {
        cin >> server[i][0] >> server[i][1];
    }
    sort(server.begin(), server.end(), cmp);
    vector<int> res;
    vector<int> idx;
    int cnt = 1;
    for (auto i : server) {
        auto it = lower_bound(res.begin(), res.end(), i[1]);
        if (it == res.end()) {
            res.push_back(i[1]);
            idx.push_back(cnt);
        } else {
            *it = i[1];
            cnt++;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << idx[i] << endl;
    }
    return 0;
}

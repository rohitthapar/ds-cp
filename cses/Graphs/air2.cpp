#include<bits/stdc++.h>
using namespace std;
const int MOD = 10000000;  
int countValidSets(int N, int P) {
    vector<vector<int>> dp(N + 1, vector<int>(P + 1, 0));
    for (int i = 1; i <= P; ++i) {
        dp[1][i] = 1;
    }
    for (int n = 2; n <= N; ++n) {
        for (int p = 1; p <= P; ++p) {
            for (int prev = 1; prev <= p; ++prev) {
                dp[n][p] += dp[n - 1][prev];
                dp[n][p] %= MOD;
            }
        }
    }
    int total_count = 0;
    for (int i = 1; i <= P; ++i) {
        total_count = (total_count + dp[N][i]) % MOD;
    }
    return total_count;
}
int main() {
    int P, N;
    cin >> P >> N;

    int result = countValidSets(N, P);
    cout << result << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int minsubarraysum(vector<int>& arr, int n) {
    int min_sum = INT_MAX;
    int curr_sum = 0;
    for (int i = 0 ; i < n; i++) {
        curr_sum = curr_sum + arr[i];
        if (curr_sum < min_sum)
            min_sum = curr_sum;
        if (curr_sum > 0)
            curr_sum  = 0;
    }
    return min_sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        arr.push_back(r);
        sum += r;
    }
    int min_sum = minsubarraysum(arr, n);
    int ans = sum + (min_sum * (-2));
    cout << ans;
}
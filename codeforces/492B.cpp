#include <bits/stdc++.h>
using namespace std;

bool check(double d, vector<int>& nums){
    // 15 5 3 7 9 14 0 --> 0 3 5 7 9 14 15
    int n = nums.size();
    for(int i = 1; i<n; i++){
        if((nums[i]-d) > (nums[i-1]+d)) return false;
    } 
    return true;
}
int main(){
    int n, l;
    cin >> n >> l;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    double streetBoundary = (double)(2 * max(nums[0], l - nums[n-1]));
    for(int i = 1;i < n;i++){
        streetBoundary = max(streetBoundary, (double)(nums[i] - nums[i-1]));
    }
    cout << setprecision(10) << streetBoundary/2 << endl;
}
// https://atcoder.jp/contests/dp/tasks/dp_b

// recursive solution

#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
int f(int idx , int k , vector<int> &h){
    if(idx == 0) return 0;
    int minSteps = INT_MAX;
    for(int j = 1;j<=k;j++){
        if(idx - j >= 0){
            int jump = f(idx - j, k,h) + abs(h[idx] - h[idx-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}
int frogJump(int n,int k,vector<int> &h){
    return f(n-1,k,h);
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    cout << frogJump(n,k,h) << endl;
    return 0;
}
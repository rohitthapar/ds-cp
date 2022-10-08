#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> a1(n,vector<int>(n));  // x-y plane
    vector<vector<int>> a2(n,vector<int>(n));  // y-z plane
    vector<vector<int>> a3(n,vector<int>(n));  // z-x plane

    // x-y plane
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a1[i][j];
        }
    }
    // y-z plane
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a1[i][j];
        }
    }
    // z-x plane
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a1[i][j];
        }
    }
}
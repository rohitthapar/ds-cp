#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    if(m < 4){
        cout << "NO" << endl;
        return;
    }
    string vika = "vika";
    int idx = 0;
    while(idx < 4){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[j][i] == vika[idx]){
                    idx++;
                }
            }
        }
    }
    if(idx == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
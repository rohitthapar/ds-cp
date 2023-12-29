#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pb push_back
#define si set<int>

using namespace std;


void solve(){
    char mat[3][3];
    int r, c;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> mat[i][j];
            if(mat[i][j] == '?'){
                r = i;
                c = j;
            }
        }
    }
    unordered_map<char, int> mp;
    mp['A'] = 0;
    mp['B'] = 0;
    mp['C'] = 0;
    for(int i=0;i<3;i++){
        mp[mat[i][c]]++;
        mp[mat[r][i]]++;
    }
    if(mp['A'] == 0) cout << 'A' << endl;
    else if(mp['B'] == 0) cout << 'B' << endl;
    else cout << 'C' << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
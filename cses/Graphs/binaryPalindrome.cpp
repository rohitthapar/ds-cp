#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;
const int maxn = 10, maxl = 1e5, lg = 20;
int n, occ[maxn][maxl];
string s;
string p[maxn];
int l[maxn], r[maxn];
int rnk[lg][maxl], whenUni[maxl], per[maxl], L;
int lcp(int i, int j){
    int ans = 0;
    for(int k = L - 1; k >= 0 && i < s.size() && j < s.size(); k--)
        if(rnk[k][i] == rnk[k][j])
            i += 1 << k, j += 1 << k, ans += 1 << k;
    return ans;
}
void buildSA(string &s){
    int n = s.size();
    int l = 0;
    auto cmp = [&l, &n](int i, int j){
        if(rnk[l][i] != rnk[l][j])
            return rnk[l][i] < rnk[l][j];
        i += 1 << l, j += 1 << l;
        return i < n && j < n ? rnk[l][i] < rnk[l][j] : i > j;
    };
    for(int i = 0; i < n; i++)
        rnk[0][i] = s[i];
    iota(per, per + n, 0);
    while(1 << l <= n){
        sort(per, per + n, cmp);
        int c = 0;
        for(int i = 0; i < n; i++){
            rnk[l + 1][ per[i] ] = c;
            c += cmp(per[i], per[i + 1]);
        }
        l++;
    }
    L = l;
    {
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(s.size() && s.top() > per[i])
                s.pop();
            if(s.size())
                whenUni[ per[i] ] = max(whenUni[ per[i] ], lcp(per[i], s.top()));
            s.push(per[i]);
        }
        s = stack<int> ();
        for(int i = n - 1; i >= 0; i--){
            while(s.size() && s.top() > per[i])
                s.pop();
            if(s.size())
                whenUni[ per[i] ] = max(whenUni[ per[i] ], lcp(per[i], s.top()));
            s.push(per[i]);
        }
    }
}
bool okl(const string &s){
    for(int i = 0; i < n; i++)
        if(count(p[i], s) < l[i])
            return 0;
    return 1;
}
bool okr(const string &s){
    for(int i = 0; i < n; i++)
        if(count(p[i], s) > r[i])
            return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> n;
    buildSA(s);
    for(int i = 0; i < n; i++){
        cin >> p[i] >> l[i] >> r[i];
        int f[p.size() + 1] = {};
        int k = 0;
        for(int i = 1; i < p.size(); i++){
            while(k && p[k] != p[i])  k = f[k];
            if(p[k] == p[i])  k++;
            f[i + 1] = k;
        }
        k = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            while(k && p[k] != s[i])  k = f[k];
            if(p[k] == s[i])  k++;
            if(k == (int)p.size()){
                ans++;
                k = f[k];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        if(okl(s.substr(i, 1))){
            whenUni[i] += i;
            int lo = i, hi = s.size();
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                (okr(s.substr(i, mid - i)) ? hi : lo) = mid;
            }
            if(!okr(s.substr(i, hi - i)))
                hi++;
            int f = max(whenUni[i] + 1, hi);
            lo = i + 1, hi = s.size() + 1;
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                (okl(s.substr(i, mid - i)) ? lo : hi) = mid;
            }
            ans += max(0, lo - f + 1);
        }
    cout << ans << '\n';
}

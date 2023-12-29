#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int mx = 0, count = 0;
    char ch = 'A';
    for(auto c : s){
        if(c == ch){
            count++;
            mx = max(mx, count);
        } else count = 1;
        ch = c;
    }
    cout << mx;
    return 0;
}
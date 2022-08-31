#include<iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
void solve(){
        int a;
        cin>>a;
        vector<int> b(a);
        priority_queue<int> pq;
        for(int i=0;i<a;i++){
            cin>>b[i];
        }
        for(int i=0;i<a;i++)
            pq.push(b[i]);

        int max_e = INT_MIN;
        int c = 1;
        while(!pq.empty()){
            int n = pq.top();
            pq.pop();
            int m = c*n;
            // cout<<m<<" ";
            max_e = max(max_e,m);
            c++;
        }
        cout<<max_e<<endl;

    }
int main()
{
    int t;
    cin>>t;
    while(t--){
    solve();
    }
return 0;
}
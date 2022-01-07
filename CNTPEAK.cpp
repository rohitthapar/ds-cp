#include<iostream>
#include<bits/stdc++.h>
// #include<limits>
using namespace std;
void min_diff(int n,int s[]){
    sort(s,s+n);
    int min_o = s[1]-s[0];
    for(int i=0;i<n;i++){
        int min_n = s[i+1] - s[i];
        min_o = min(min_n,min_o);
    }
    cout<<min_o<<endl;

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        min_diff(n,s);
    }
    return 0;
}
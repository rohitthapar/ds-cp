#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,i=0;
        cin>>n;
        if(n%2!=0){
            cout<<"NO"<<endl;
            break;
        }
        while(n>3)
        {
            if(n%4==0){
                n=n-4;
            }
        }
        if(n==2 || n==3){
            cout<<"YES"<<endl;
        }
    }
}
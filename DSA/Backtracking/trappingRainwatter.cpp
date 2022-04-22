#include<bits/stdc++.h>
using namespace std;

int trw(int arr[],int n){
    int lmax[n],rmax[n];
    lmax[0] = arr[0];
    for(int i=1;i<n;i++){
        lmax[i]=max(arr[i],lmax[i-1]);
    }
    for(int i=0;i<n;i++){
        cout<<lmax[i]<<" ";
    }

    rmax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(arr[i],rmax[i+1]);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<rmax[i]<<" ";
    }
     int wc=0;
    for (int i = 1; i < n-1; i++)
    {
        if(arr[i]<min(lmax[i], rmax[i]))
        {
            wc=wc+ min(lmax[i], rmax[i])-arr[i];
        }
    }
    cout<<endl<<wc;
    return wc;
    // return 0;
}
int main(){
    int n;
    cin>>n;
    // vector<int> h(n);
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    trw(arr,n);
    return 0;
}
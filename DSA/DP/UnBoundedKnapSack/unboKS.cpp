#include<iostream>
using namespace std;
int UNknapsack(int wt[],int val[],int w, int n){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+UNknapsack(wt,val,w-wt[n-1],n),UNknapsack(wt,val,w,n-1));
    }
    else return UNknapsack(wt,val,w,n-1);
}
int main(){
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];

    }
    for(int i=0;i<n;i++){
        cin>>val[i];

    }
    cout<<UNknapsack(wt,val,w,n)<<endl;    

    return 0;
}
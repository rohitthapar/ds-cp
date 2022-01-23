#include<iostream>
using namespace std;
int countSum(int arr[],int n,int s){
    if(n == 0){
        return 0;
    }
    if(s == 0){
        return 1;
    }
    if(arr[n-1]<=s){
        return countSum(arr,n-1,s) + countSum(arr,n,s-arr[n-1]);
    }
    else return countSum(arr,n-1,s);
}
int main(){
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countSum(arr,n,s)<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int countSubset(int arr[],int n,int s){
    if(n == 0){
        return 0;
    }
    if(s == 0){
        return 2;
    }
    if(arr[n-1]<=s){
        return countSubset(arr,n-1,s-arr[n-1]) +  countSubset(arr,n-1,s);
    }
    else return countSubset(arr,n-1,s);
}
int main(){
    int n,diff;
    int sum = 0;
    cin>>n>>diff;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum = sum + arr[i];
    }
    int s = (sum + diff)/2;
    cout<<countSubset(arr,n,s)<<endl;
    return 0;
}
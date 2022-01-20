#include<iostream>
using namespace std;
int binarySearch_rec(int arr[],int l,int r,int x){
    if(r>=l){
        int mid = l+(r-l)/2;
    if(arr[mid] == x){
        return mid;
    }
    if(arr[mid] > mid){
        return binarySearch_rec(arr,l,mid-1,x);
    }
    else return binarySearch_rec(arr,mid+1,r,x);
    }
    return -1;

}
int binarySearch_It(int arr[],int l,int r,int x){
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid]<x){
            r = mid+1;
        }
        else l = mid - 1;
   }
   return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<binarySearch_It(arr,0,n-1,x)<<endl;
    return 0;
}
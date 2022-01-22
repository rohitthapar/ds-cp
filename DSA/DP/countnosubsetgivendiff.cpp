#include<iostream>
using namespace std;

int countSum(int arr[],int n,int sum){
    if(sum == 0){
        return 1;
    }
    // int n = sizeof(arr);
    if(n == 0){
        return 0;
    }
    if(arr[n-1]<=sum){
        return countSum(arr,n-1,sum-arr[n-1]) + countSum(arr,n-1,sum);
    }
    else return countSum(arr,n-1,sum);

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
    cout<<countSum(arr,n,s)<<endl;
    return 0;
}
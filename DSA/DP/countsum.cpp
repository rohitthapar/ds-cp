#include<iostream>
using namespace std;
//recursion code
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
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countSum(arr,n,sum)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
//subset sum 
// vector<int>dp;
// bool subsetSum(int arr[], int n, int S){
//     if(S==0){
//         return true;
//     }
//     if(n==0 && S!=0){
//         return false;
//     }

//     if(arr[n-1]<=S){
//         return subsetSum(arr,n-1,S-arr[n-1]) || subsetSum(arr,n-1,S);
//     }
//     else return subsetSum(arr,n-1,S);
// }

// int minDiffernece(int arr[],int range){
//     int n = sizeof(arr);
//     for(int i=0;i<range/2;i++){
//         if(subsetSum(arr,i,range) == true){
//             dp.push_back(arr[i]);
//         }
//     }

// }
// recursice code
int findMin(int arr[],int n,int c_sum,int sum){
    if(n == 0){
        return abs(sum - c_sum - c_sum);
    }
    return min(findMin(arr,n-1,c_sum+arr[n-1],sum),findMin(arr,n-1,c_sum,sum));
}

int findSum(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum +arr[i];
    }
    return findMin(arr,n,0,sum);

}
int main(){
    int n,range = 0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // range = range + arr[i];
    }
    cout<<findSum(arr,n)<<endl;
    // cout<<subsetSum(arr,n,range)<<endl;
    return 0;
}
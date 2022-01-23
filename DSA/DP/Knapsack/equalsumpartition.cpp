#include<iostream>
using namespace std;
bool subsetSum(int arr[], int n, int S){
    if(S==0){
        return true;
    }
    if(n==0 && S!=0){
        return false;
    }

    if(arr[n-1]<=S){
        return subsetSum(arr,n-1,S-arr[n-1]) || subsetSum(arr,n-1,S);
    }
    else return subsetSum(arr,n-1,S);
}
bool equalSum(int arr[]){
    int n = sizeof(arr);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    else return subsetSum(arr,n,sum/2);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<equalSum(arr)<<endl;
    return 0;
}


// class Solution {
// public:
//     bool subsetsum(vector<int> arr,int sum)
//     {
//         int n=arr.size();
//         bool t[n+1][sum+1];
//         for(int i=0;i<n+1;i++)
//             for(int j=0;j<sum+1;j++)
//             {
//                 if(i==0)t[i][j]=false;
//                 if(j==0)t[i][j]=true;    
//             }
        
//         for(int i=1;i<n+1;i++)
//            for(int j=1;j<sum+1;j++)
//            {
//                if(arr[i-1]<=j)
//                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
//                else
//                    t[i][j]=t[i-1][j];
//            }
//         return t[n][sum];     
//     }
    
    
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size(),sum=0;
//         for(int i=0;i<n;i++)
//             sum+=nums[i];
//         if(sum%2!=0)
//             return false;
//         return subsetsum(nums,sum/2);
//     }
// };
// https://leetcode.com/problems/jump-game-ii/
#include<iostream>
using namespace std;
int jumpGame(int arr[],int n){
    int *dp = new int[n+1];

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<jumpGame(arr,n)<<endl;
}

// nums = [2,3,1,1,4]
// 2
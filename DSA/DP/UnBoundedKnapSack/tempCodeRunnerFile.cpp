if(arr[n-1]<=s){
        return dp[n][s] = countSum(arr,n-1,s) + countSum(arr,n,s-arr[n-1]);
    }
    else return countSum(arr,n-1,s);
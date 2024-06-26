int longestPalindrome(string x){
    int n = x.length();
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
     int mL = 0;
    for(int i = 0;i<n;i++){
        dp[i][i] = true;
    }
    int start = 0;
   
    for(int i = 0;i<n-1;i++){
        if(x[i] == x[i+1]){
            dp[i][i+1] = true;
            start = i;
            mL = 2;
        }
    }
    for(int k = 3;k<=n;k++){
        for(int i = 0;i<n-k+1;i++){
            int j = i+k-1;
            if( dp[i+1][j-1] && x[i] == x[j]){
                dp[i][j] = true;
                if(k>mL){
                    start = i;
                    mL = k;
                   
                }
            }
        }
    }

    return mL;

}
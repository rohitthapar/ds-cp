#include<iostream>
#include<math.h>
#include<vector>
#include<climits>
using namespace std;
int mincount(int n){
    if(n<=3){
        return n;
    }
    if(sqrt(n)-floor(sqrt(n)) == 0){
        return 1;
    }
    int ans = n;
    for(int i=1;i<=n;i++){
        int temp = i*i;
        if(temp>n){
            break;
        }
        else ans = min(ans,1+mincount(n-temp));
    }
    return ans;

}
//memoization

int mincount_m(int n){
    int *ans = new int[n+1]();
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<=n;i++){
        ans[i] = INT_MAX;
        if(sqrt(n)-floor(sqrt(n))==0){
            ans[n] = 0;
        }
        for(int j = 1;i-(j*j)>0;j++){
            ans[i] = min(ans[i],ans[i-(j*j)]);
        }
        ans[i] +=1;
    }
    int res = ans[n];
    delete [] ans;
    return res;
}
int mincount_dp(int n){
    int *ans = new int[n+1]();
    for(int i=0;i<=n;i++){
        ans[i]=i;
    }
    if(n<=3){
        return n;
    }
    if(sqrt(n)-floor(sqrt(n)) == 0){
        ans[n]=1;
    }
    for(int i=4;i<=n;i++){
        for(int x=1;x<ceil(sqrt(n));x++){
            int temp = x*x;
            if(temp>n){
                break;
            }
            else ans[i] = min(ans[i],1+ans[n-temp]);
        }
    }
    int res = ans[n];
    delete [] ans;
    return res;

}
int mincount_dp2(int n){
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=sqrt(i);j>=1;j--){
            if(ans[i]!=0){
                ans[i] = min(ans[i],ans[i-(j*j)]);
            }
        else ans[i] = 1+ans[i-(j*j)];
        }
    }
    int res = ans[n];
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<mincount_dp2(n)<<endl;
    return 0;
}
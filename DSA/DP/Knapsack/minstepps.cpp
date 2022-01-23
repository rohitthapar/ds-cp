#include<iostream>
#include<climits>
using namespace std;
int minsteps_n(int n,int *ans){
    if(n == 1){
        ans[n] = 0;
        return 0;
    }
    int y = INT_MAX, z = INT_MAX;
    if(ans[n-1] == -1){
        ans[n-1] = minsteps_n(n-1,ans);
    }
    if(n%2==0){
        if(ans[n/2] == -1){
            ans[n/2] = minsteps_n(n/2,ans);
        }
            y=ans[n/2];
    }
     if(n%3==0){
        if(ans[n/3] == -1){
            ans[n/3] = minsteps_n(n/3,ans);
        }
            z=ans[n/3];
    }
    ans[n] = 1+min(ans[n-1],min(y,z)) ;
    return ans[n];
}
int minsteps_n(int n){
    // int *ans = new int[n+1]{-1};
    // return minsteps_n(n,ans);
}
int minsteps_dp(int n){
    int *ans = new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    // cout<<ans[3];
   ans[0]=0;
   ans[1]=1;
   for(int i=2;i<n+1;i++){
       int r = 1+ans[i-1];
       if(n%2==0){
           r=min(r,ans[n/2]);
       }
       if(n%3==0){
           r=min(r,ans[n/3]);
       }
       ans[i] = r;
   }
   return ans[n];

}
int main(){
    int n;
    cin>>n;
    cout<<minsteps_dp(n)<<endl;
    return 0;
}
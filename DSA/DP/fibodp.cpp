#include<iostream>
using namespace std;

int fibo_dp(int n){
    int *ans = new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<n+1;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fibo_dp(n)<<endl;
    return 0;
}
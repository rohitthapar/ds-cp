#include<iostream>
using namespace std;
int fibo_better(int n, int *ans){
    if(n<=1){
        ans[n] = n;
        return n;
    }
    if(ans[n-1]==0){
        ans[n-1] = fibo_better(n-1,ans); 
    }
    if(ans[n-2]==0){
        ans[n-2] = fibo_better(n-2,ans);
    }
    ans[n] = ans[n-1] + ans[n-2];
    return ans[n];

}
int fibo_better(int n){
    int *ans = new int[n+1];
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    return fibo_better(n,ans);
}

int main(){
    int n;
    cin>>n;
    cout<<fibo_better(n)<<endl;
    return 0;
}
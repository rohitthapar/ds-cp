#include<iostream>
#include<vector>
using namespace std;
int activity(vector<int> start,vector<int> finish, int n){
    int count = 0;
    for(int j=1,i=0;j<n;j++){
        if(start[j]>=finish[i]){
            count++;
            i=j;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int k;
    vector<int>start,finish;
    for(int i=0;i<n;i++){
        cin>>k;
        start.push_back(k);
    }
    for(int i=0;i<n;i++){
        cin>>k;
        finish.push_back(k);
    }
    int ans = activity(start,finish,n);
    cout<<ans;

    return 0;
}

// 6
// 1 3 0 5 8 5 
// 2 4 6 7 9 9
// 3

//solution not optimised  --> will work on that
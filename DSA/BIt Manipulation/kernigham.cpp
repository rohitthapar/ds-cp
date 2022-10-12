#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt = 0;
    while(n!=0){
        int r = n & -n;
        n -= r;
        cnt++;
    }
    cout<<cnt<<endl;

}
// Q. Kernighan’s Algorithm 
// 		x-=rbsm
// 		rbsm = x&(-x)


// also known as hamming weight


// __builtin_popcount(x): This function is used to count the number of one’s(set bits) in an integer. 


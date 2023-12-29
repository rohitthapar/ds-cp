#include <bits/stdc++.h>
using namespace std;

// can two applicants have the same desired apartment 

//brute force ---> greedy + O(n2) approach
int bf(vector<int>& desiredAppartmentSize, vector<int>& appartmentSize, int k){
    int n = desiredAppartmentSize.size(); // applicants 
    int m = appartmentSize.size(); // apartments

}



int main(){
    int n, m, k; // applicants, apartments, maximum allowed difference
    int a, b;
    cin >> n >> m >> k;
    vector<int> desriedAppartmentSize(n);
    for(int i=0;i<n;i++){
        cin >> a;
        desriedAppartmentSize[i] = a;
    }

    vector<int> appartmentSize(m);
    for(int i=0;i<m;i++){
        cin >> b;
        appartmentSize[i] = b;
    }
    return 0;
}
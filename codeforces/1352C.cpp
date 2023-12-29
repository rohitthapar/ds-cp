#include <bits/stdc++.h>
using namespace std;

int minimumcost(int input1,int input2,int input3,int**input4){
    int node=input1;
    int edge=input2;
    int mul=input3;
    unordered_map<int,int>m;
    for(int i=0;i<edge;i++){
        m[input4[i][0]]++;
        m[input4[i][1]]++;
    }
    int count=0;
    for(auto it:m)if(it.second>1)count++;
    return count*mul;
}

int main(){
    int input4[6][2] = {{0,1},{1,2},{3,4},{2,4},{2,6},{5,2}};
    cout << minimumcost(7,6,5, input4) << endl;

}
int solve(int a, int b, int c){
    c = c*1000; // convert to g;
    int minApple = 0, maxApple = 0;
    if(c%a == 0) maxApple = c/a;
    if(c%b == 0) minApple = c/b;
    if(c%a != 0 && c%b != 0) return -1;
    else return minApple + maxApple;
}

// int main() {
//     cout << solve(300, 333, 1);
// }


//
// Created by Rohit Thapar on 30/06/23.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n--){
        int p,v,t;
        cin >> p >> v >> t;
        int sum = p + v + t;
        if(sum >= 2) count++;
    }
    cout << count << endl;
    return 0;
}
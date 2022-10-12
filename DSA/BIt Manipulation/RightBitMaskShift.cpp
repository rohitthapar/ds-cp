#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rbms = n&(-n);
    cout<<bitset<8>(rbms).to_string();
}


// Q. Right Most Set Bit Mask. ———> Used in Fenwick Tree, Cunningham Algorithm 

// 		76  ——> 25 0’s 1001100
// 		RSBM —> 25 0’s 0000 100 

// 		Calculate in O(1)
// 		Last One 
		
// 		rsbm = x & x’’ ( x and 2’s complement of x)


// https://www.geeksforgeeks.org/position-of-rightmost-set-bit/

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int rbms = n&(-n);
//     string bin = bitset<8>(rbms).to_string();
//     int n = bin.size();


// }
// https://www.interviewbit.com/problems/scramble-string/ 
// to check whether it is a scrambled string or not
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool solve(string s,string x){
    if(s.compare(x) == 0){
        return true; // both the strings are equal so return true
    }
    int n = s.size();
    if(n<=1){
        return false; // already checked and the strings cannot be empty
    }
     // condition 1 to check if swapping occur, Condition 2 to check if swapping doesnt occur
//       // we are checking recursively the first part of A, and 2nd part of B in cond 1 and vice versa
//       // we are checking recursively the first part of A to the first part of B in cond 2 and vice versa
    bool flag = false;
    for(int i = 1;i<n;i++){
        if((solve(s.substr(0,i),x.substr(n-i,i)) && solve(s.substr(i,n-i),x.substr(0,n-i))) ||
            (solve(s.substr(0,i),x.substr(0,i)) && solve(s.substr(i,n-i),x.substr(i,n-i)))){
                flag = true;
                break;
            }
    }
    return flag;


}
int main(){
    string s,x;
    cin>>s>>x;
    int n = s.size();
    int y = x.size();
    if(n != y) {
        return false; // different sizes
    }
    if(n == 0 || y == 0){
        return true; //both are empty so both are scrambled
    }
    return solve(s,x);
}

























// unordered_map<string,bool> mp;
//    bool solve(string A, string B){
   
//    if(A==B) // a==b i.e if both are equal then they are scrambled
//     return true;
   
//    int n = A.size();
//    if(n <= 1)
//     return false;  // as already checked if they are equal, here if they are not equal then they cant be
//                   // cant be scrambled

//    string key = A + " " + B; // making the key to check in our hashmap
//    if(mp.find(key) != mp.end()) // if found
//        return mp[key];

//    bool flag = false;

//    for(int i=1;i<=n-1; i++){
     
//       // condition 1 to check if swapping occur, Condition 2 to check if swapping doesnt occur
//       // we are checking recursively the first part of A, and 2nd part of B in cond 1 and vice versa
//       // we are checking recursively the first part of A to the first part of B in cond 2 and vice versa
     
//        if((solve(A.substr(0,i), B.substr(n-i)) && solve(A.substr(i), B.substr(0,n-i)))  
//            || (solve(A.substr(0,i), B.substr(0,i)) && solve(A.substr(i), B.substr(i)))){
        
//            flag = true;
//            break;
//        }
//    } 
//    return mp[key] = flag;
//  }

//   int Solution::isScramble(const string A, const string B) {

//    mp.clear();

//    if(A.size()!=B.size()) // different sizes
//        return false;

//    else if(A.size() == 0 && B.size()==0) // if both empty then both are scrambled
//        return true;
//    else
//        return solve(A,B);
//   }
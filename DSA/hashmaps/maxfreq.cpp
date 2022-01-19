#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;

int maxFreq(int* a, int size){
    unordered_map<int,bool> hash;
    for(int i=0;i<size;i++){
        hash[a[i]]++;
    }
    int max = 0, result = -1;
    for(auto i: hash){
        if(max < i.second){
            result = i.first;
            max = i.second;
        }
    }
    return result;
}
int main(){
    int a[]={2 ,12 ,2 ,11 ,12 ,2 ,1 ,2 ,2 ,11 ,12 ,2 ,6};
    int size = 13;
    cout << maxFreq(a,size);

    return 0;
}
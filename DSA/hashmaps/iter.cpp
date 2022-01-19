// #include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> ourmap;
    ourmap["ab"] = 1;
    ourmap["ab1"] = 2;
    ourmap["ab2"] = 3;
    ourmap["ab3"] = 4;
    ourmap["ab4"] = 5;
    ourmap["ab5"] = 6;


    unordered_map<string, int>::iterator it = ourmap.begin();
    while(it!=ourmap.end()){
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
        it++;
    }

    return 0;
}
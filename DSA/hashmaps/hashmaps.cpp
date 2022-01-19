#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
        //inbuilt hashmaps     
        unordered_map<string,int> ourmap;


        //insert
        pair<string,int> p("abc",1);
        ourmap.insert(p);
        ourmap["def"] = 2;

        cout<<ourmap["abc"]<<endl;
        cout<<ourmap.at("abc")<<endl;

        cout<<ourmap["ghi"]<<endl;
        cout<<ourmap.at("def")<<endl;
        

        cout<<ourmap.size();

        // check permission

        if(ourmap.count("ghi")>0){
            cout<<ourmap.at("ghi")<<endl;
        }
        ourmap.erase("ghi");


    return 0;
}
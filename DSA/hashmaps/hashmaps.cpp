#include<iostream>
#include<list>
#include<cstring>
#include<map>
#include<unordered_map>
using namespace std;

//hashtable to implement phonebook


int main(){
        // map<string,int> marksMap;
        // marksMap["Rohit"] = 10;
        // marksMap["ROhan"] = 100;
        // marksMap["Rahul"] = 1000;
        // map<string,int> :: iterator it;
        // for(it=marksMap.begin();it!=marksMap.end();it++){
        //     cout<<(*it).first<<" "<<(*it).second<<"\n";
        // }
        // cout<<marksMap.empty();

    unordered_map<int,char> mp;
    mp = {{1,'a'},{2,'b'}};
    // cout<<mp[1];
    unordered_map<int,char> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}
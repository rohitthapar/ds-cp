#include<iostream>
#include<list>
#include<cstring>
#include<map>
#include<unordered_map>
using namespace std;

//hashtable to implement phonebook


int main(){
    map<string,int> marksMap;
    marksMap["Rohit"] = 10;
    marksMap["ROhan"] = 100;
    marksMap["Rahul"] = 1000;
    map<string,int> :: iterator it;
    for(it=marksMap.begin();it!=marksMap.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }
    cout<<marksMap.empty();
    return 0;
}
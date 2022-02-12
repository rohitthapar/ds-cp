#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){
    int x;
    cin>>x;
    string s = to_string(x);
    int n = s.size();
    char min_e = s[0];
    for(int i=1;i<n;i++){
        if(s[i] < min_e && s[i]!='0'){
            min_e = s[i];
        }
        else continue;
    }
    for(int i=0;i<n;i++){
        if(s[i]!=min_e && s[i]>=53){
            s[i] = 57-s[i]+48;
        }
    }
    int r = stoi(s);
    cout<<r;
    return 0;
}
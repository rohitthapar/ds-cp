#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> ans;
   

    while(t--){
        string s;
        getline(cin,s);
         int f=1;
        int n = s.length();
        for(int i = 0;i<n-1;i++){
            if(s[i-1] == '1' && s[i] == '0' && s[i+1] == '1' || s[i-1] == '0' && s[i] == '1' && s[i+1] == '0'){
                f=0;
                break;
            }
        }
        // if(f==0){
        //     cout<<"Good\n";
        // }
        // else cout<<"Bad\n";
        cout<<endl;
        cout<<f<<endl;

        ans.push_back(f);
    }
    // for(int i=0;i<ans.size();i++){
    //     if(ans[i]==0){
    //         cout<<"Good"<<endl;
    //     }
    //     else cout<<"Bad"<<endl;
    // }
    return 0;
}
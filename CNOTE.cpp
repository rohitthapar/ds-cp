#include<iostream>
#include <utility>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k,n;
        int f=0;
        cin>>x>>y>>k>>n;
        for(int i=0;i<n;i++){
            int pl = x-y;
            pair<int,int>nb;
            cin>>nb.first>>nb.second;
            if(x<y){
               f=1; // cout<<"LuckyChef"<<endl; 
            }
            else if(nb.first>=pl && k>=nb.second){
                f=1;  // cout<<"LuckyChef"<<endl; 
            }
            //  else f=0; //cout<<"UnluckyChef"<<endl; 
        
        }
        if(f==1){
            cout<<"LuckyChef"<<endl;
        }
        else cout<<"UnluckyChef"<<endl;
    }
    return 0;
}
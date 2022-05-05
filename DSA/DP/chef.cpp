#include<iostream>
using namespace std;

struct chef{
    int start,finish,compartment;
};
bool compare(chef c1, chef c2){
    return (c1.finish < c2.finish);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        chef res[n];
        for(int i=0;i<n;i++){
            cin>>res[i].start>>res[i].finish>>res[i].compartment;
        }
        // for(int i=0;i<n;i++){
        //     cout<<res[i].start<<" "<<res[i].finish<<" "<<res[i].compartment;
        //     cout<<endl;
        // }
    }
    return 0;
}
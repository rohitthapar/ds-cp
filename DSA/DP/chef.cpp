#include<iostream>
#include<algorithm>
using namespace std;

struct chef{
    int start,finish,compartment;
};
bool compare(chef c1, chef c2){
    if(c1.compartment == c2.compartment)return (c1.finish < c2.finish);
    return (c1.compartment < c2.compartment);
}
int maxComp(chef res[], int n){
    sort(res,res+n,compare);
    int i=0;
     int s = (n>0) ? 1:0;
    for(int j=1;j<n;j++){
        if(res[j].compartment!=res[i].compartment){
            s++;
            i=j;
        }
        else if(res[j].start >= res[i].finish){
            s++;
            i=j;
        }
    }
    return s;
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
        cout<<maxComp(res,n)<<endl;
    }
    return 0;
}
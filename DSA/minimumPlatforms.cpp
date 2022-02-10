//  int maxMeetings(int start[], int end[], int n)
//    {
//        // Your code here
//        vector<pair<int,int>>v;
//        for(int i=0;i<n;i++){
//            v.push_back({end[i],start[i]});
//        }
//        sort(v.begin(),v.end());
//        int ans = 0;
//        int en = 0;
//        for(int i=0;i<n;i++){
//            if(v[i].second > en){
//                ans++;
//                en = v[i].first;
//            }
//        }
       
//        return ans;
//    }

#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arival[n],dept[n];
    for(int i=0;i<n;i++){
        cin>>arival[i];
    }

    for(int i=0;i<n;i++){
        cin>>dept[i];
    }
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arival[i],dept[i]));
    }
    sort(v.begin(),v.end());
    int pn = 1,res=1;
    int i=1,j=0;
    while(i<n && j<n){
        if(v[i].first<=v[j].second){
            pn++;
            i++;
        }
        else {
            pn--;
            j++;
        }
        res=max(pn,res);
    }
    cout<<res;
    return 0;
}

// 6
// 0900 0940 0950 1100 1500 1800
// 0910 1200 1120 1130 1900 2000
// 3
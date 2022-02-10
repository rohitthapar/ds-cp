// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
   static bool comp(const pair<int,int> &p1, const pair<int,int> &p2)
   {
       return p1.second<p2.second;
   }
   int activitySelection(vector<int> start, vector<int> end, int n)
   {
       vector<pair<int,int>> v;
       for(int i=0;i<n;i++)
       v.push_back({start[i],end[i]});
       sort(v.begin(),v.end(),comp);
       int c=1;
       int End=v[0].second;
       for(int i=1;i<n;i++)
       {
           if(v[i].first>End)
           {
               c++;
               End=v[i].second;
           }
       }
       return c;
   }

};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pb push_back
#define si set<int>

using namespace std;
     
    bool isPerfectSquare(long long num) 
    {
        if (num < 0) 
        {
            return false;
        }
     
        long long sqrtNum = static_cast<long long>(sqrt(num));
        return sqrtNum * sqrtNum == num;
    }
     
    int main()
    {
        int t;
        cin>>t;
     
        while(t--)
        {
            int n;
            cin>>n; 
            int A[n];
            for(int i=0; i<n; i++)
            {
                cin>>A[i];
            }
     
            long long sum=0;
            for(int i=0; i<n; i++)
            {
                sum+=A[i];
            }
     
            if (isPerfectSquare(sum)) 
            {
                cout <<"YES"<<endl;
            } 
            else 
            {
                cout <<"NO"<<endl;
            }
     
        }
     
        return 0;
    }
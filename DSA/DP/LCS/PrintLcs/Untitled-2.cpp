#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
 ll n;
 cin>>n;
 while(n--)
 {
     string s,f;
     cin>>s>>f;
     map<ll,vector<ll>>m;
     for(int i=0;i<s.length();i++)
     {
         if(i!=s.length()-1)
       m[s[i]].push_back(s[i+1]);
       else
       {
          m[s[i]].push_back(s[0]);
       }
     }
     bool flag=false;
     for(int i=0;i<f.length();i++)
     {
        ll x=f[i];
        if(i+1!=f.lengh()-1&&find(m[x].begin(),m[x].end(),f[i+1])!=m.end())
        continue;
        else if(i+1==f.lengh()-1&&find(m[x].begin(),m[x].end(),f[0])!=m.end())
        continue;
        else
        {
            flag=false;
            break;
        }
     }
     if(flag)
     {
       cout<<"f"<<endl;}
     else
     cout<<"foul"<<endl;

 }
}

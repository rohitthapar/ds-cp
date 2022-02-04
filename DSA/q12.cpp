#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
      ll n;
      cin>>n;
      ll m = n;
      ll p = 1;
      if(n==1){
          cout<<0<<" "<<1<<" "<<3<<endl;
          continue;
      }
      while(m){
          if(m%2==1){
              break;
          }
          p=p*2;
          m=m/2;
      }
      if(p==n){
          cout<<n<<" "<<n+1<<" "<<n+2<<endl;
      }
      else {
          cout<<p<<" "<<(p^n)<<" "<<n<<endl;
      }

    }
}

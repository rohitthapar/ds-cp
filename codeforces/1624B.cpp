#include<iostream.h>
typedef long long int ll;
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;

    int na = b - (c - b);
    if(na >= a and na%a == 0 and na!=0){
        cout<<"YES\n";
        return;
    }
    int nb = a + (c-a)/2;
    if(nb >= b and (c-a)%2 ==0 and nb%b == 0 and nb!=0){
        cout<<"YES\n";
        return; 
    }
    int nc = a + 2*(b-a);
    if(nc >= c and nc%c == 0 and nc!=0){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
 return 0;
}
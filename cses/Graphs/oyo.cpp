#include<bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define mp make_pair

#define pb push_back

#define pob pop_back()

#define mod 1000000007

#define max INT_MAX

#define min INT_MIN

#define fi first

#define se second

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

set<int> v;

void binarypalindrome(int s, int e, int x){
    if(s>e){
        v.insert(x);
        return;
    }
    binarypalindrome(s+1,e-1,x);
    if(s==e) binarypalindrome(s+1,e-1, x+ pow(2,s));
    else binarypalindrome(s+1,e-1, x+ pow(2,s)+ pow(2,e));
    return;
}

int main()

{

    fast_cin();

    int n,t;

    v.insert(0);v.insert(1);v.insert(3);

    for(int i=3; i<32; i++)

    {

        int c= pow(2,i-1)+1;

        binarypalindrome(1,i-2, c);

    }

    cin>>t;

    while (t--)

    {

        cin>>n;

        auto ptr=v.lower_bound(n);

        auto ptr2= ptr--;

        if(abs(n-*ptr)<abs(n-*ptr2))

        cout<<abs(n-*ptr)<<endl;

        else

        cout<<abs(n-*ptr2)<<endl;

    }

       

    return 0;

}
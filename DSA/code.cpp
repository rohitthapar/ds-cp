#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    int pairs = 0;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    int i = 0;
    int j = n-1;
    while(i<j){
        if(a[i] + a[j] == sum){
                pairs++;
                i++;
                j--;
        }
        else if(a[i] + a[j] > sum)j--;
        else i++;
    }
    cout<<pairs<<endl;
    return 0;
}

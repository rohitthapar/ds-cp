#include <bits/stdc++.h>
 using namespace std;

int MaxSum(vector<int> arr, int n)
{
    int include = arr[0];
    int exclude = 0;
    int exclude_new;
    int i;
 
    for (i = 1; i < n; i++)
    {
        exclude_new = (include > exclude) ? include : exclude;
        include = exclude + arr[i];
        exclude = exclude_new;
    }
    return ((include > exclude) ? include : exclude);
}
 
int main()
{
    vector<int> arr;
    int i=0;
    while(i!=-1){
        cin>>i;
        arr.push_back(i);
    }
    cout<<MaxSum(arr, arr.size())<<endl;
    
}
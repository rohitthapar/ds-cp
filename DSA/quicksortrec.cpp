#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
 
    for (int j = p; j <= r- 1; j++){
        if (arr[j] <= x){
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[r]);
    return (i + 1);
}
 
void quickSort(int arr[], int p, int r){
    if (p < r){
        int q = partition(arr, p,r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    cout<<"Sorted Array ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
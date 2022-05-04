#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=low+(high-low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
int main()
{
    int arr[30], num;
    cin>>num;
    for (int i = 0; i < num; i++) { cin>>arr[i];
    }
    merge_sort(arr, 0, num-1);
    cout<<"Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout<<arr[i]<<" ";
    }
}

// #include<iostream>
// using namespace std;
// void Display(int Arr[],int n)
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<Arr[i]<<" ";
// 	}
// 	cout<<"\n";	
// }

// void Merge(int Arr[], int mid, int l, int h)
// {
//     //cout<<mid;
// 	int B[h+1];
// 	//int mid=(l+h)/2;
// 	int i=l,j=mid+1,k=0;
// 	while(i<=mid && j<=h)
// 	{
// 		if(Arr[i]<Arr[j])
// 		{
// 			B[k]=Arr[i];
// 			i++;
// 		}else
// 		{
// 			B[k]=Arr[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	while(i<mid)
// 	  {
// 	  	B[k]=Arr[i];
// 	  	k++;
// 	  	i++;
// 	  }
// 	while(j<h)
// 	 {
// 	 	B[k]=Arr[j];
// 	 	k++;
// 	 	j++;
// 	 }
// 	 for(i=l;i<=h;i++)
//         Arr[i]=B[i];
// }

// void MergeSort(int arr[], int l, int h)
// {
//     if (l < h)
//     {
//         int m = l + (h - l) / 2;
//         MergeSort(arr, l, m);
//         MergeSort(arr, m + 1, h);
//         Merge(arr, m, l, h);
//     }
// }


// int main(){
// 	int size;
// 	cout<<"Enter size"<<endl;
// 	cin>>size;
// 	int A[size];
// 	cout<<"Enter array elements"<<endl;
// 	for(int i=0;i<size;i++)
// 	{
// 		cin>>A[i];
// 	}

// 	MergeSort(A,0,size-1);
//     cout<<"After Merging"<<endl;
//     Display(A,size);
	
// 	return 0;
// }
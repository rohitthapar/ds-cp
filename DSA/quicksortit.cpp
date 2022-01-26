#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int l, int h){
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}
void quickSort(int arr[], int l, int h){
	int s[h - l + 1];
	int t = -1;
	s[++t] = l;
	s[++t] = h;
	while (t >= 0) {
		h = s[t--];
		l = s[t--];
		int p = partition(arr, l, h);
		if (p - 1 > l) {
			s[++t] = l;
			s[++t] = p - 1;
		}
		if (p + 1 < h) {
			s[++t] = p + 1;
			s[++t] = h;
		}
	}
}
void printArr(int arr[], int n){
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << " ";
}
int main(){
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	quickSort(arr, 0, n - 1);
    cout<<"Sorted Array ";
	printArr(arr, n);
	return 0;
}

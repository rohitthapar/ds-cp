// #include<iostream>
// #include<vector>
// using namespace std;
// int activity(vector<int> start,vector<int> finish, int n){
//     int count = 0;
//     for(int j=1,i=0;j<n;j++){
//         if(start[j]>=finish[i]){
//             count++;
//             i=j;
//         }
//     }
//     return count;
// }
// int main(){
//     int n;
//     cin>>n;
//     int k;
//     vector<int>start,finish;
//     for(int i=0;i<n;i++){
//         cin>>k;
//         start.push_back(k);
//     }
//     for(int i=0;i<n;i++){
//         cin>>k;
//         finish.push_back(k);
//     }
//     int ans = activity(start,finish,n);
//     cout<<ans;

//     return 0;
// }

// // 6
// // 1 3 0 5 8 5 
// // 2 4 6 7 9 9
// // 3

// //solution not optimised  --> will work on that

// // use 2d vector and helper function to sort the finish time and then apply 
// // the greedy approach


// C++ program for activity selection problem
// when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;

// A job has a start time, finish time and profit.
struct Activitiy
{
	int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, activityCompare);

	cout << "Following activities are selected n";

	// The first activity always gets selected
	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	// Consider rest of the activities
	for (int j = 1; j < n; j++)
	{
	// If this activity has start time greater than or
	// equal to the finish time of previously selected
	// activity, then select it
	if (arr[j].start >= arr[i].finish)
	{
		cout << "(" << arr[j].start << ", "
			<< arr[j].finish << "), ";
		i = j;
	}
	}
}

// Driver program
int main()
{
	Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
									{5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMaxActivities(arr, n);
	return 0;
}

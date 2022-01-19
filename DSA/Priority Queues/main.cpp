#include<iostream>
#include<bits/stdc++.h>
#include "priorityqueue.cpp"
using namespace std;     


//k sorted array in decreasing order  
//in a k sorted array element can move only k-1 times 
// to the left or k-1 times to the right to get to its 
// correct position
//10 12 15 6 9 -> valid example of k-sorted array where k = 3
void ksorted(int arr[],int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int j=0;
    for(int i = k;i<n;i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while(!pq.empty()){
        arr[j] = pq.top();
        pq.pop(); 
        j++;
    }
}


int main(){
    int arr[] = {10,12,6,7,9};
    int k = 3;
    ksorted(arr,5,k);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" "; 
   }

    // priorityQueue pq;

    // //insert queue
    // pq.insert(10);
    // pq.insert(1);
    // pq.insert(2);
    // pq.insert(100);
    // pq.insert(13);
    // pq.insert(45);
    // pq.insert(55);

    // cout<<pq.getSize()<<endl;
    // cout<<pq.getMin()<<endl;

    // // cout<<endl;
    // while(!pq.isEmpty()){
    // cout<<pq.removeMin()<<" ";
    // }
    // cout<<endl;

     

     //inbuilt priority queue
    // priority_queue<int> pq;
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);     
    // while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }
    return 0;
 
}

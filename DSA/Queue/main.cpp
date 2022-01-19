#include<iostream>
#include<bits/stdc++.h>
#include "Queueusingarray.h"
using namespace std;

int main(){
    QueueArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(40);
    q.enqueue(40);


    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
#include "StackArray.cpp"
using namespace std;

int main(){
    StackArray s;
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(30);

    cout<<s.top()<<endl;
    cout<<s.pop();
   

    return 0;

}
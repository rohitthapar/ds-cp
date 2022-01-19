#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "../node.cpp"


void fun(node *head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<endl;
    if(head->next!=NULL)
        fun(head->next->next);
        cout<<head->data<<endl;
    
}
int main(){
    node *head = dataInput();
    print(head);
    fun(head);
    return 0;
}
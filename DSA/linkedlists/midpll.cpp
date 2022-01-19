#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "../node.cpp"

//mid point of a linked list
void midData(node *head){
    node *slow=head;
    node *fast=head->next;
    node *temp=head;
    while(temp!=NULL)
    {
        if(fast==NULL){
            cout<<slow->data<<" "<<endl;
        }
        else if(fast->next==NULL){
            cout<<slow->data<<" "<<endl;
        }
    slow=slow->next;
    fast=fast->next->next;
    temp=temp->next;
    }
}
void rotateBetween(node *head, int left,int right){
    if(left>right){
        return;
    }
    
}


int main(){
    node *head = dataInput();
    print(head);
    // cout<<endl;
    midData(head);
    // reverseLL(head);
    // print(head);
    return 0;
}
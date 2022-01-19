#include<bits/stdc++.h>
#include "StacksLL.cpp"
using namespace std;
node *midpoint(node *head){
    node *slow=head;
    node *fast=head->next;
    node *temp=head;
    node *prev=NULL;
    while(temp!=NULL)
    {
        if(fast==NULL){
            prev = slow;
        }
        else if(fast->next==NULL){
            prev = slow;
        }
    slow=slow->next;
    fast=fast->next->next;
    temp=temp->next;
    }
    if(fast){
        prev = slow->next;
    }

    return prev;
}
node *reverseLL(node *head){
    node *newHead = NULL;
    if(head->next==NULL){
        newHead = head;
        return;
    }
    reverseLL(head->next);
    node *temp = head->next;
    temp->next = head;
    head->next = NULL;

    return head;
}

int main(){
       return 0;
}
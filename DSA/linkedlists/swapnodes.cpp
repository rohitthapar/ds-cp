#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// #include "../node.cpp"
#include "../nodechar.cpp"


node* swapPairs(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *temp = head, *temp_1=head->next, *temp_2=head->next->next;
    temp->next=temp_2;
    temp_1->next=temp;
    temp->next=swapPairs(temp_2);
    return temp_1;
}

node *deleteDuplicate(node *head){
        node *temp = head;
        while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        
        else{
            temp=temp->next;
        }
    }
    
    return head;
}
//remove nth node from the end 
int size(node* head){
    if(head == NULL){
        return 0;
    }
    else return 1+size(head->next);
}
node* removeFromLast(node* head,int n){
    int i = size(head) - n;
    deleteNodeR(head,i);
    return head;
}

// }   check soluiton

int main(){
    node *head = dataInput();
    // print(head);
    // head=swapPairs(head); 
    // cout<<size(head)<<endl;
    // head = removeFromLast(head,0);
    print(head);
    return 0;
}
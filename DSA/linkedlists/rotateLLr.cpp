#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "../node.cpp"


// node *rev_LL_3(node *head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     node *smallans = rev_LL_3(head->next);
//     node *tail = head->next;
//     head->next=NULL;
//     return smallans;
// }
class Pair{
    public:
    node *head;
    node *tail;
};
Pair rev_LL_2(node *head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans; 
     }
     Pair smallans = rev_LL_2(head->next);
     smallans.tail->next=head;
     head->next=NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail=head;
    return ans;
}
node *rev_LL_2_r(node *head){
    return rev_LL_2(head).head;
}

// reverse a linked list 
// node* revLL(node *head){
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     node *smallAns = revLL(head->next);
//     node *temp = smallAns;
//     while(temp->next == NULL){
//         temp = temp->next;
//     }
//     temp->next=head;
//     head->next=NULL;
//     return smallAns;
// }
int main(){

    node *head = dataInput();
    print(head);
    node *newhead=rev_LL_2_r(head);
    print(newhead);
    return 0;
}
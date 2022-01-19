#include<iostream>
using namespace std;
#include "node.cpp"

// node* insertData(){
//     int data;
//     cin>>data;
//     node *head = NULL;
//     node *tail = NULL;
//     while(data!=1){
//         node *newNode = new node(data);
//         if(head == NULL){
//             head = newNode;
//             tail = newNode;
//         } else {
//         tail->next=newNode;
//         tail=newNode;
//         }
//         cin>>data;
//         }
//        return head;
// }
// void print(node *head){
//     node *temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
node *newNode(int data){
    node *newNode = new node(data);
    newNode->next=NULL;
    return newNode;
}
node *insertDataR(node *head, int data){
    if(head == NULL){
        return newNode(data);
    }
    else 
        head->next=insertDataR(head->next,data);
    return head;
}
void print(node *head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}
    int main(){

    return 0;
}


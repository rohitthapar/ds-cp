#include <iostream>
using namespace std;
#include "node.cpp"

node* dataInput(){
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1){
        node *newNode = new node(data);
        if(head == NULL){
        head = newNode;
        tail = newNode;
        }
        else {
            // node *temp = head;
            // while(temp->next!=NULL){
            //     temp = temp->next;
            // }
            tail->next=newNode;
            // tail = tail->next; 
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
node* insertNode(node *head, int i, int data){
    node *newNode = new node(data);
    int count = 0;
    node *temp = head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(count< i-1){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next=newNode;

    return head;
}

// node *deleteNode(Node *head, int pos)
// {
//     int count=0;
//     node *temp=head;
//     if(head==NULL){
//         return NULL;
//     }
//     if(pos==0){
//         temp=head->next;
//         delete head;
//         return temp;
//     }
//     while(temp->next!=NULL&&count<pos-1){
//         temp=temp->next;
//         count++;
//         }
//     if(temp->next!=NULL){
//     node *a=temp->next;
//     temp->next=a->next;
//     delete a;    
//     }
//     return head;
// }

node *deleteNodeR(node *head, int pos){
    if(head == NULL){
        return NULL;
    }
    if(pos == 0){
        node *temp=head->next;
        delete(head);
        return temp;
    }
    head->next=deleteNodeR(head->next,pos-1);
    return head;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL)
    {
    cout << temp->data<<" "; 
    temp = temp->next;
    }
}
int main()
{
    node *head= dataInput();
    print(head);
    // int i, data;
    // cin>>i>>data;
    // head = insertNode(head,i,data);
    // print(head);
    // // node n1(1);
    cout<<endl;
    deleteNodeR(head,2);
    print(head);



    // node *head=&n1;
    // node n2(2);
    // node n3(3);
    // node n4(4);
    // node n5(5);
    // n1.next=&n2;
    // n2.next=&n3;
    // n3.next=&n4;
    // n4.next=&n5;

    // print(head);
    // // cout<<n1.data<<" "<<n2.data<<endl;
    // cout<<head->data;                              

    //dynamically
    // node *n3 = new node(10);
    // node *head=n3;
    // node *n4 = new node(20);
    // n3->next=n4;
    // node *n5 = new node(50);
    // n4->next=n5;
    // node *n6 = new node(90);
    // n5->next=n6;
    // node *n7 = new node(120);
    // n6->next=n7;

    // print(head);

}
#include<bits/stdc++.h>
using namespace std;

class node {
    public :
    char data;
    node *next;
    node(char data) {
        this -> data = data;
        next = NULL;
    }
}; 

node* dataInput(){
    char data;
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
            tail->next=newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

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
cout<<endl;
}
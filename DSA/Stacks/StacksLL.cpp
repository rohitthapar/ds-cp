#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data){
        this -> data = data;
        next = NULL;
    }
};

class stackLL{
    node *head;
    int size;

    public:
    stackLL(){
        head = NULL;
        size = 0;
    }


int getSize(){
    return size;
}
bool isEmpty(){
    return size == 0;
}
void push(int data){
    node *newNode = new node(data);
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    size++;
}
void pop(){
    if(isEmpty())
        cout<<"Stack Empty"<<endl;
    else {
            cout<<"The popped element is "<< head->data <<endl;
            node *temp=head;
            delete(temp);
            head=head->next;
   }
   size--;
}
void display(){
        node *temp1 = head;
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
        }
        else{
            while(temp1!=NULL){
                cout<<temp1->data<<" ";
                temp1=temp1->next;
            }
        }
}
};


// int main(){
//     stackLL s;
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);
//     s.push(70);
//     s.push(30);

//     s.display();
//     s.pop();
//     s.pop();
//     s.pop();
//     s.pop();
//     cout<<s.getSize();
//     return 0;
// }
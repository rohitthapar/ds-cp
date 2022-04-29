#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void preOrder(struct Node* node){
    // Time Complexity -> O(N)
    // Space Complexity -> O(N)
    if(node == NULL) return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(struct Node* node){
    if(node == NULL)return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}


void inOrder(struct Node* node){
    if(node == NULL)return;
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}
int main(){

    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrder(root);
    return 0;
}


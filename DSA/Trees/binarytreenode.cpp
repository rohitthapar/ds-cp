#include<bits/stdc++.h>
#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInputLevel(){
    int rootData;
    cout<<"Enter Root Data ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        BinaryTreeNode<int> * front = pendingNode.front();
        pendingNode.pop();

        cout<<"Enter left child of "<<front->data<<" ";
        int lcd;
        cin>>lcd;
        if(lcd!=-1){
            front->left = new BinaryTreeNode<int>(lcd);
            pendingNode.push(front->left);
        }
        cout<<"Enter right child of "<<front->data<<" ";
        int rcd;
        cin>>rcd;
        if(rcd!=-1){
            front->right = new BinaryTreeNode<int>(rcd);
            pendingNode.push(front->right);
        }
    } 
    return root;
}


void printLevelWise(BinaryTreeNode<int>* root){
   queue<BinaryTreeNode<int>*>pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        BinaryTreeNode<int>*front=pendingnode.front();
        pendingnode.pop();
        cout<<front->data<<":";
        cout<<"L:";
        if(front->left){
            cout<<front->left->data;
            pendingnode.push(front->left);
        }
        else{
            cout<<" ";
        }
        cout<<",";
        cout<<"R:";
        if(front->right){
            cout<<front->right->data;
            pendingnode.push(front->right);
        }
        else{
            cout<<" ";
        }
        cout<<endl;
    }
    return;
}
void print(BinaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L "<<root->left->data;
    }

    if(root->right!=NULL){
        cout<<"R "<<root->right->data;
    }

    cout<<endl;
    print(root->left);
    print(root->right);
}

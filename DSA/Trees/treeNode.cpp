#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

template <typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;
    treeNode(T data){
        this->data = data;
    }
    ~treeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
// void print

treeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter Root Data ";
    cin>>rootData;
    treeNode<int> * root = new treeNode<int>(rootData);

    int n;
    cout<<endl<<"Enter number of children ";
    cin>>n;

    for(int i=0;i<n;i++){
        treeNode<int>*child = takeInput();
        root->children.push_back(child);

    }
    return root;
}
treeNode<int>* takeInputLevel(){
    int rootData;
    cout<<"Enter root data ";
    cin>>rootData;
    treeNode<int> * root = new treeNode<int>(rootData);
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        treeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;

        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            treeNode<int> *child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
// void printLevel(treeNode<int>* root){
//     queue<treeNode<int>*> printLevelNode;
//     printLevelNode.push(root);
//     cout<<root->data<<":";
//     while(printLevelNode.size()!=0){
//         treeNode<int>* front = printLevelNode.front();
//         printLevelNode.pop();

//         for(int i=0; i<front->children.size();i++){
//             cout<<front->children[i]->data<<" ";
//         }
//         cout<<endl;
//         cout<<front->data<<":";

//     }
// }

void printLevelWise(treeNode<int>* root) {
    // Write your code here
    queue<treeNode<int>*>pendingnode;
    pendingnode.push(root);
    while(!pendingnode.empty()){
        cout<<pendingnode.front()->data<<":";
        for(int i=0;i<pendingnode.front()->children.size();i++){
            cout<<pendingnode.front()->children[i]->data;
            if(i!=pendingnode.front()->children.size()-1){
                cout<<",";
            }
            pendingnode.push(pendingnode.front()->children[i]);
        }
        pendingnode.pop();
        cout<<endl;
    }
    return;
}
void preorder(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void print(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
       print(root->children[i]);
    }
}
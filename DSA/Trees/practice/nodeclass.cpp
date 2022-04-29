#include <bits/stdc++.h>
#include <iostream>
typedef unsigned long ul;

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

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        vector<int> level;
        unsigned long size = q.size();
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}


int main(){

    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
//    preOrder(root);
//    cout<<endl;
//    postOrder(root);
//    cout<<endl;
//    inOrder(root);
    vector<vector<int>> level_ans = levelOrder(root);
    ul n = level_ans.size();
    ul m = level_ans[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<level_ans[n][m]<<" ";
        }
        cout << endl;
    }
    return 0;
}


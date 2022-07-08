#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right; 

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// level order traversal 
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
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    return 0;
}
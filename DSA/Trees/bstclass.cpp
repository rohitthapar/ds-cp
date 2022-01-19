#include<iostream>
#include<bits/stdc++.h>
#include "binarytreenode.cpp"
typedef BinaryTreeNode<int>* btn;

using namespace std;

class bst{
    private:
    btn root;
    
    bool hasData(int data, btn node){
        if(node == NULL){
            return false;
        }
        if(node->data == data){
            return true;
        } else if(data < node->data){
            return hasData(data,node->left);
        }
        else return hasData(data,node->right);
    }

    
};

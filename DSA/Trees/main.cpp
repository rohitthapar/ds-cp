#include<iostream>
#include<bits/stdc++.h>
#include "treeNode.cpp"
void greaterNodes(treeNode<int>* root,int x){
    queue<treeNode<int>*>maxNode;
    int j=0;
    maxNode.push(root);
    while(!maxNode.empty()){
        if(maxNode.front()->data>x){
              j++;
            }
        for(int i=0;i<maxNode.front()->children.size();i++){
            maxNode.push(maxNode.front()->children[i]);
        }
        maxNode.pop();
    }
    cout<<j<<" ";
    return;
}
void justGreaterNode(treeNode<int>* root,int x){
    queue<treeNode<int>*>maxNode;
    int j=0;
    maxNode.push(root);
    while(!maxNode.empty()){
        if(maxNode.front()->data>x){
              cout<<maxNode.front()->data<<" ";
              break;
            }
        for(int i=0;i<maxNode.front()->children.size();i++){
            maxNode.push(maxNode.front()->children[i]);
        }
        maxNode.pop();
    }
    cout<<j<<" ";
    return;
}
//  treeNode<int> * maxSumNode(treeNode<int>* root){
//     queue<treeNode<int>*>maxSumNode;
//     maxSumNode.push(root);
//     int max=0,sum=0;
//     while(!maxSumNode.empty()){
//         // if(max>=sum){
//             // max=sum;
//         // } else { 
//            for(int i = 0;i<maxSumNode.front()->children.size();i++){
//                sum+=maxSumNode.front()->children[i]->data;
//                maxSumNode.push(maxSumNode.front()->children[i]);
//         } 
//         // }  
//     }

// }
//structure identical of two nodes
bool sameTree(treeNode<int>* root_a,treeNode<int>* root_b){
    bool ans=false;
    if(root_a->children.size()!=root_b->children.size()){
        ans=false;
    }
    if(root_a->children.size()==root_b->children.size()){
        if(root_a->data == root_b->data){
            for(int i=0;i<root_a->children.size();i++){
                sameTree(root_a->children[i],root_b->children[i]);
                ans = true;
            }
        }
    }
    return ans;
}
using namespace std;
int main(){
    treeNode<int> *root = takeInputLevel();
    // treeNode<int> *root_b = takeInputLevel();
    // cout<<sameTree(root_a,root_b)<<" ";
    // treeNode<int> *root1 = takeInputLevel();

    // printLevelWise(root);
    int n;
    cin>>n;
    justGreaterNode(root,n);
    // delete root;
    return 0;
}

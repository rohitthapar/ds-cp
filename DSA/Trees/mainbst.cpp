#include<iostream>
#include "binarytreenode.cpp"
#include "../node.cpp"
typedef BinaryTreeNode<int>* btn;
// typedef node<int>* nl;

//search bst element 
bool searchBST(btn root, int element){
    if(root == NULL){
        return false;
    }
    if(root->data ==  element){
        return true;
    }
    if(element > root->data){
       return searchBST(root->right,element);
    }    
    
    if(element < root->data){
        return searchBST(root->left,element);
    }    
}
//print elements in a given range 
void printRange (btn root, int minR, int maxR){
    if(root == NULL){
        return;
    }
    if (root->data>minR && root->data<maxR){
        cout<<root->data<<" ";
    }
    if(root->data<minR){
        printRange(root->left,minR,maxR);
    }
    if(root->data>maxR){
        printRange(root->right,minR,maxR);
    }

        //  printRange(root->left,minR,maxR);
        //  printRange(root->right,minR,maxR);


}


//bst to sorted linked list 
template <typename T>
class node {
    public :
    T data;
    node<T> *next;
    node(T data) {
        this -> data = data;
        this -> next = NULL;
    }
}; 

pair <node<int>*,node<int>*> construct(btn root){
    if(root == NULL){
        pair<node<int>*,node<int>*>p;
        // p.first=NULL;
        // p.second=NULL;
        return p;
    }
    pair <node<int>*,node<int>*> pL=construct(root->left);
    pair <node<int>*,node<int>*> pR=construct(root->right);
    node<int>* temp=new node<int>(root->data);

    if(pL.first==NULL && pL.second==NULL){
        pair<node<int>*,node<int>*> pan=make_pair(temp,temp);
        return pan;
    }
    else {
        pL.second->next=temp;
        temp->next=pR.first;
    }
    pair<node<int>*,node<int>*> pans;
    pans.first=pL.first;
    pans.second=pR.second;

    return pans;

}

node<int>* constructBST(btn root){
    pair<node<int>*,node<int>*> p;
    p=construct(root);
    return p.first;
}

//return path problem
vector<int>* getPath(btn root, int data){
    if(root == NULL){
        return NULL;
    }
                                                                                  
    
}


int main(){
    btn root =  takeInputLevel();
    system("clear");
    int element;
    // cout<<"Enter Element"<<" ";
    // cin>>element;
    // cout<<endl;
    // printRange(root,2,5);
    // cout<<searchBST(root,element);
    // cout<<root1->data;
    delete root;
    return 0;
}
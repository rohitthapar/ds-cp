#include<iostream>
#include "binarytreenode.cpp"
typedef BinaryTreeNode<int>* btn;

// void swap(btn root1, btn root2){
//     int temp;
//     temp
// }
//number of nodes
int numNodes(btn root){
if(root ==  NULL){
    return 0;
}
    return 1+numNodes(root->left)+numNodes(root->right);
}
//inorder traversal
void inorder(btn root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//preorder traversal
void preorder(btn root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
//height of the tree 
int height(btn root){
    if(root == NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
//mirror binary tree --  replace mirroring values 
void mirror(btn root){
    if(root ==  NULL){
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    // mirror(root->right);

}
//construct tree from preorder inorder
// btn buildTree(int* in, int* pre, int inS, int inE, int preS, int preE){
//     if(inS>inE){
//         return NULL;
//     }
//     int rootData = pre[preS];
//     int rootIndex = -1;
//     for(int i = inS;i<=inE;i++){
//         if(in[i]==rootData){
//             rootIndex = i;
//             break;
//         }
//     }

// }
int maxE(btn root){
    if(root == NULL){
        return 0;
    }
    int max_e = max(maxE(root->left),maxE(root->right));
    return max_e;
}
int minE(btn root){
    if(root == NULL){
        return 0;
    }
    int min_e = min(minE(root->left),minE(root->right));
    return min_e;
}
pair<int,int> compareEle(btn root){

    pair<int,int> ans ;
    ans.first = maxE(root);
    ans.second = minE(root);

    return ans;
}

int sumNodes(btn root){
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    return sum+root->data+sumNodes(root->left)+sumNodes(root->right);
}
int heightTree(btn root){
    if(root ==  NULL){
        return 0;
    }
    int lheight = heightTree(root->left);
    int rheight = heightTree(root->right);
    int h = max(lheight,rheight);
    return 1+h;
}
//balanced binary tree
bool balance(btn root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    //  if(root->left == NULL || root->right == NULL){
    //     return false;
    // }
    int l = heightTree(root->left);
    int r = heightTree(root->right);

    if(l == r){
        return true;
    }
    else return false;
}

int main(){
    BinaryTreeNode<int>* root =  takeInputLevel();
    system("clear");
    // cout<<height(root);
    // preorder(root);
    // mirror(root);
//    pair<int,int>ans = compareEle(root);
//    cout<<"Max "<<ans.first<<endl;
//    cout<<"Min "<<ans.second<<endl;

    // printLevelWise(root);
    // cout<<sumNodes(root)<<endl;
    cout<<balance(root)<<endl;
    delete root;
    return 0;
}
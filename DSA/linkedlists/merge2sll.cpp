#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include "../node.cpp"

//merging of two sorted linked lists 
node *mergeLL(node *h1,node *h2){
    node *res = NULL;
    if (h1 == NULL){
        return(h2);
    } else if (h2 == NULL) {
        return(h1);
    }
    if (h1->data <= h2->data){
        res=h1;
        res->next = mergeLL(h1->next,h2);
    } else {
        res=h2;
        res->next = mergeLL(h1,h2->next);
    }
    return(res);
}

int main(){
    node *h1=dataInput();
    node *h2=dataInput();
    print(h1);
    print(h2);
    node *mer = mergeLL(h1,h2);
    print(mer);
    return 0;
}
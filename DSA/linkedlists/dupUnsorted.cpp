/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{
    unordered_map<int, int> mp;
    Node* temp = head;
    while(temp!= NULL && temp->next!=NULL){
        if(mp.find(temp->data) != mp.end() && mp[temp->data] > 1){
            //it exists
            temp->next = temp->next->next;
            mp[temp->data]++;
        }
        else{
            mp[temp->data]++;
            temp = temp->next;
        }
        return head;
    }
    // Write your code here
}

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the Linked list.
*/

#include <unordered_map>

Node *removeDuplicates(Node *head)
{

    Node *curr = head;

    // Keep track of previous node.
    Node *prev = NULL;

    unordered_map<int, bool> seen;

    // Iterate over the given linked list.
    while (curr != NULL)
    {
        int val = curr->data;

        if (seen[val])
        {
            // Node has been encountered before, so its a duplicate.
            // Firstly update the next pointer of the previous node.
            prev->next = curr->next;

            // Delete the duplicate node.
            delete curr;

            // Move on to the next node.
            curr = prev->next;
        }
        else
        {
            // Node is seen for the first time, so add it to hash table.
            seen[val] = true;

            // Move on to the next node.
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
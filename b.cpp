[10:26 am, 19/09/2022] Vibhav CCS: #include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node *loopStart;
    bool isLooped;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
        isLooped = false;
        loopStart = NULL;
    }
};

Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    return temp;
}
Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}

int main()
{
    int n;
    cin>>n;
    n--;
    char ch;
    int x,y;
    cin>>ch>>x;
    Node* head = new Node(x);
    int flag=1;
    while(n--)
    {
        cin>>ch;
    
        if(ch=='I')
        {
            cin>>x;

            if(flag==0)
            {
                head = insertBegin(head,x);
                flag=1;
            }
            else
            {
                head=insertEnd(head,x);
                flag=0;
            }
            
        }
        if (ch=='S')
        {
            cin>>x>>y;
            Node* curr = head;
            for(int i=1;i<x;i++)
            {
                curr=curr->next;
            }
            Node * temp1=curr;
            for(int i=x;i<y;i++)
            {
                curr=curr->next;
            }
            Node * temp2=curr;

            temp1->prev->next=temp2->next;
            temp2->next->prev=temp1->prev;
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            temp1->prev=curr;
            curr->next=temp1;
            temp2->next=temp1;
            curr=temp1;
            while(curr->next!=temp1)
            {
                curr->isLooped=true;
                curr->loopStart=temp1;
                curr=curr->next;
            }

        }
        if (ch=='D')
        {
            Node* curr = head;
            while(curr!=NULL)
            {
                cout<<curr->data<<" ";
                curr=curr->next;
                if(curr->isLooped==true)
                {
                    if(curr->loopStart==curr->next)
                    {
                        cout<<curr->data<<" ";
                        cout<<curr->loopStart->data<<" ";
                        break;
                    }
                    if(curr->next->loopStart==curr->next)
                    {
                        cout<<curr->data<<" ";
                        cout<<curr->loopStart->data<<" ";
                        curr=curr->next;
                    }
                    
                    
                }
            }
        }

    }
}
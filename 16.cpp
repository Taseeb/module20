#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val; Node *next; Node *prev;

    Node(int v)
    {
        val = v; next = NULL; prev = NULL;
    }
};

Node* get_tail(Node* &head,Node* &tail);

void insert_node(Node* &head,Node* &tail,int val)         
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head = newNode; tail = head; return;
    }

    tail = get_tail(head,tail); tail->next = newNode; newNode->prev = tail; tail = newNode;                                 
}

void display(Node *n)
{
    for(;n!=NULL;n=n->next)
    {
        cout<<n->val;
        if(n->next!=NULL)
        {
            cout<<" <-> ";
        }
    }
}

void reverse_display(Node *n)
{
    for(;n!=NULL;n=n->prev)
    {
        cout<<n->val;
        if(n->prev!=NULL)
        {
            cout<<" <-> ";
        }
    }
}

Node* get_tail(Node* &head,Node* &tail)
{
    if(head==NULL || head->next==NULL)
    {
        tail = head; return tail;
    }

    Node* cur = head;

    while(cur->next!=NULL)
    {
        cur = cur->next; 
    }

    tail = cur; return tail;
}

int main()
{
    Node* head = NULL; Node* tail = NULL;
    while(1)
    {
        cout<<"Want to insert value(y/n)?: ";char ch; cin>>ch;
        
        if(ch=='y')
        {
            int val; cout<<"enter val: "; cin>>val; insert_node(head,tail,val); display(head);
        }

        else if(ch=='n') break; getchar();

        cout<<endl;
    }

    reverse_display(tail);

    delete head; delete tail; return 0;
}
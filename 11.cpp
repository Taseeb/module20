#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val; Node *next;

    Node(int v)
    {
        val = v; next = NULL;
    }
};

void insert_node(Node* &head,int val)         
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head = newNode; return;
    }

    Node* tail = head;

    while(tail->next!=NULL)
    {
        tail = tail->next;
    }

    tail->next = newNode;                                       
}

void display(Node *n)
{
    for(;n!=NULL;n=n->next)
    {
        cout<<n->val;
        if(n->next!=NULL)
        {
            cout<<" -> ";
        }
    }
}

int main()
{
    Node* head = NULL;
    while(1)
    {
        cout<<"Want to insert value(y/n)?: ";char ch; cin>>ch;
        
        if(ch=='y')
        {
            int val; cout<<"enter val: "; cin>>val; insert_node(head,val); display(head);
        }

        else if(ch=='n') break; getchar();

        cout<<endl;
    }
    delete head; return 0;
}
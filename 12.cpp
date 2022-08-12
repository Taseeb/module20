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

void insertAtTail(Node* &head,int val);
void insertAtHead(Node* &head,int val);
void insert_node_by_position(Node* &head,int pos,int val);
void display(Node *n);
int length(Node *n);


void insertAtTail(Node* &head,int val)         
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

void insertAtHead(Node* &head,int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_node_by_position(Node* &head,int pos,int val)           
{
    if(pos==0)
    {
        insertAtHead(head,val); return;
    }

    if(pos==length(head))
    {
        insertAtTail(head,val); return;
    }
    
    Node *newNode = new Node(val); 
    Node *current = head;
    for(int i=0;i<=pos-2;++i)                                   
    {
        current=current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
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

int length(Node *n)
{
    int count=0;
    for(;n!=NULL;n=n->next)
    {
        count++;
    }
    return count;
}

int main()
{
    Node *head = NULL;int val,pos; 
    
    cout<<"press 0 to exit"<<endl;
    cout<<"1 to insert at Head"<<endl;
    cout<<"2 to insert at Tail"<<endl;
    cout<<"3 to insert at specific position"<<endl<<endl;

    while(1)
    {
        int op; cout<<"Enter op: ";cin>>op;  

        if(op==0) break;
        
        else if(op==1) 
        {
            cout<<"Enter val: "; cin>>val; insertAtHead(head,val); cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else if(op==2) 
        {
            cout<<"Enter val: "; cin>>val; insertAtTail(head,val); cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else if(op==3) 
        {
            cout<<"Enter pos & val: "; cin>>pos>>val; 
            if(pos>=0 && pos<=length(head)) insert_node_by_position(head,pos,val);
            else cout<<"Invalid position\n";
            cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else cout<<"Invalid code.Please enter again\n";
    }
    delete head; return 0;
}

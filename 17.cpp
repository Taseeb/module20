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

void insertAtTail(Node* &head,Node* &tail,int val);
void insertAtHead(Node* &head,Node* &tail,int val);
void insert_node_by_position(Node* &head,Node* &tail,int pos,int val);
void display(Node *n);
int length(Node *n);
Node* get_tail(Node* &head,Node* &tail);

void insertAtTail(Node* &head,Node* &tail,int val)         
{
    Node *newNode = new Node(val);

    if(head==NULL)
    {
        head = newNode; tail = head; return;
    }

    tail = get_tail(head,tail); tail->next = newNode; newNode->prev = tail; tail = newNode;                                 
}

void insertAtHead(Node* &head,Node* &tail,int val)
{
    Node *newNode = new Node(val);
    if(head==NULL) 
    {
        head = newNode; tail = head; return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

    tail = get_tail(head,tail);
}

void insert_node_by_position(Node* &head,Node* &tail,int pos,int val)           
{
    if(pos==0)
    {
        insertAtHead(head,tail,val); return;
    }

    if(pos==length(head))
    {
        insertAtTail(head,tail,val); return;
    }
    
    Node *newNode = new Node(val); 
    Node *current = head;
    for(int i=0;i<=pos-2;++i)                                   
    {
        current=current->next;
    }
    newNode->next = current->next; current->next->prev = newNode;
    current->next = newNode; newNode->prev = current;

    tail = get_tail(head,tail);
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

int length(Node *n)
{
    int count=0;
    for(;n!=NULL;n=n->next)
    {
        count++;
    }
    return count;
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
    Node *head = NULL;Node *tail = NULL;int val,pos; 
    
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
            cout<<"Enter val: "; cin>>val; insertAtHead(head,tail,val); cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else if(op==2) 
        {
            cout<<"Enter val: "; cin>>val; insertAtTail(head,tail,val); cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else if(op==3) 
        {
            cout<<"Enter pos & val: "; cin>>pos>>val; 
            if(pos>=0 && pos<=length(head)) insert_node_by_position(head,tail,pos,val);
            else cout<<"Invalid position\n";
            cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else cout<<"Invalid code.Please enter again\n";
    }

    reverse_display(tail);
    delete head; delete tail;return 0;
}

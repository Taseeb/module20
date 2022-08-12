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
int count_node(Node *n);
void move_tail(Node* &head);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void delete_node_by_position(Node *&head,int pos);

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

    if(pos==count_node(head))
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

void deletionAtHead(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Nothing to delete\n"; return;
    }

    Node *dlt = head; head = head->next; delete dlt;
}

void deletionAtTail(Node* &head)
{
    if(head==NULL)
    {
        cout<<"Nothing to delete\n"; return;
    }

    else if(head->next==NULL)
    {
        deletionAtHead(head); return;
    }
    
    Node *cur = head;

    while(cur->next->next!=NULL)
    {
        cur = cur->next;
    }

    Node *dlt = cur->next; cur->next = NULL; delete dlt;
}

void delete_node_by_position(Node *&head,int pos)
{
    if(head==NULL)
    {
        cout<<"Nothing to delete\n"; return;
    }

    else if(pos<0 || pos>count_node(head)-1)
    {
        cout<<"Invalid position\n"; return;
    }

    else if(pos==0)
    {
        deletionAtHead(head); return;
    }

    else if(pos==count_node(head)-1)
    {
        deletionAtTail(head); return;
    }

    Node *cur = head;

    for(int i=0;i<=pos-2;++i)
    {
        cur = cur->next;
    }

    Node *dlt = cur->next; cur->next = cur->next->next; delete dlt;
}

void move_tail(Node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        cout<<"nothing to move\n"; return;
    }

    Node* cur = head;

    while(cur->next->next!=NULL) cur = cur->next;

    Node* tail = cur->next; tail->next = head; head = tail;

    cur->next = NULL; 
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

int count_node(Node *n)
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
    cout<<"3 to insert at specific position"<<endl;
    cout<<"4 delete node at a specific position"<<endl;
    cout<<"5 to move tail to the begining"<<endl;
    cout<<"6 to show total nodes"<<endl<<endl;

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
            if(pos>=0 && pos<=count_node(head)) insert_node_by_position(head,pos,val);
            else cout<<"Invalid position\n";
            cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else if(op==4)
        {
            cout<<"enter pos: "; cin>>pos; 

            delete_node_by_position(head,pos);
            if(head==NULL) 
            {
                cout<<"Empty List\n"; continue;
            } 
            cout<<"Forward print:  ";display(head); cout<<"\n";
        }

        else if(op==5)
        {
            move_tail(head); display(head); cout<<endl;
        }

        else if(op==6)
        {
            cout<<"size is: "<<count_node(head)<<endl;
        }
        
        else cout<<"Invalid code.Please enter again\n";
    }
    delete head; return 0;
}
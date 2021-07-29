#include<iostream>

using namespace std;

class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
};
class DoublyLinkedList
{
    private:
    Node* head=NULL;
    public:
    void create_list(int data);
    void display_list();
};
void DoublyLinkedList :: create_list(int data)
{
    Node *t=new Node();
    t->data=data;
    t->next=NULL;
    t->prev=NULL;
    if(head==NULL)
    {
        head=t;
        
    }
    else
    {
        
        
        Node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
        t->prev=p;
        
        
    }
}

void DoublyLinkedList :: display_list()
{
    Node *p=head;
    cout<<" Nodes of a Doubly linked list: ";
    while(p->next!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

} 
int main()
{
    DoublyLinkedList d1;
    d1.create_list(6);
    d1.create_list(8);
    d1.create_list(67);
    d1.create_list(456);
    d1.display_list();
    return 0;
}
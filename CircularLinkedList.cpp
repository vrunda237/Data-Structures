
#include<iostream>

using namespace std;

class Node
{
	public:
    int data;
    Node* next;
};
class CircularList
{ 
    private:
    Node* head;
    
    public:
        void create_list(int A[], int n);
        void display();
        void insert_Node(int index,int data);
        void delete_node(int index);
    
};
void CircularList::create_list(int A[], int n)
{
    int i;
    Node *t,*last;
    head=new Node();
    head->data=A[0];
    head->next=head;
    
    last=head;
    
    for(int i=1;i<n;i++)
    {
        
        t=new Node();
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
    
}
void CircularList::display()
{
    Node *p=head;
    cout<<"Nodes of a Circular linked list"<<endl;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
        
        
    }while(p!=head);
    cout<<endl;
}
void CircularList::insert_Node(int index,int data)
{

    // Inserting before head node
    if(index==0)
    {
        Node *t=new Node();
        t->data=data;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            Node *p=head;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }

    }
    //Inserting at any position
    else
    {
        Node *last=head;
        
        Node *t=new Node();
        
        
    
        for(int i=0;i<index-1;i++)
        {
            
            last=last->next;
        
            
        }
        t->data=data;
        t->next=last->next;
        last->next=t;
        last=NULL;
    }
}

void CircularList::delete_node(int index)
{
	//deleting  a head node

    Node *p=head;
    int i,x;
    if(index==1)
    {
        
        while(p->next!=head)
        {
            p=p->next;
        }
        if(head==p)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            x=head->data;
            delete head;
            head=p->next;

        }
        
        
    }
    else
    {
       
        int i=1;
        while(i<index-1)
        {
            p=p->next;
            i++;
        }
        Node *q=p->next;
        p->next=q->next;
        int x=q->data;
        delete q;


    }
}

int main()
{
    CircularList c1;
    int A[]={2,4,5,6,7,89,45,34};
    c1.create_list(A,8);
    c1.display();
    /*c1.insert_Node(4,87);
    c1.display();
    c1.insert_Node(0,56);
    c1.display();
    */
    c1.delete_node(4);
    c1.display();
    c1.delete_node(1);
    c1.display();
    
}

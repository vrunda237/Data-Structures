#include <iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;
		node()
		{
			next=NULL;
		}
};


class linkedlist
{
	node *head;
	public:
		void insert_begin(int data);
		void insert_end(int data);
		void insert_pos(int data,int pos);
		void delete_begin();
		void delete_end();
		void delete_pos(int p);
		void display();
};


void linkedlist::insert_begin(int data)
{
	node* temp=new node();
	temp->data=data;
	temp->next=head;
	head=temp;
}
void linkedlist::insert_end(int data)
{
	node* p=new node();
	p->data=data;
	p->next=NULL;
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
	
}
void linkedlist::insert_pos(int data,int pos)
{
	node *p,*q;
	node* temp=new node();
	temp->data=data;
	p=head;
	for(int i=0;i<pos-1 && p;i++)
	{
		q=p;
		p=p->next;
	
	}
	q->next=temp;
	temp->next=p;
		
	
}
void linkedlist::delete_begin()
{
	node* p=new node;
	p=head;
	head=head->next;
	int x=p->data;
	cout<<" node with value "<<x<<" is deleted."<<endl;
	delete p;
}
void linkedlist::delete_end()
{
	node* temp=head;
	node*p=NULL;
	while(temp->next!=NULL)
	{
		p=temp;
		temp=temp->next;
		
	}
	p->next=NULL;
	delete temp;
	
}
void linkedlist::delete_pos(int pos)
{
	node *p,*q;
	p=head;
	for(int i=0;i<pos-1;i++)
	{
		q=p;
		p=p->next;
		
	}
	q->next=p->next;
	delete p;
}

void linkedlist::display()
{
	node *temp=head;
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{

	linkedlist l1;
	l1.insert_begin(8);
	l1.insert_begin(6);
	l1.insert_begin(9);
	l1.insert_begin(5);
	
	l1.display();
	l1.insert_end(56);
	l1.insert_end(78);
	l1.display();
	l1.insert_pos(67,3);
	l1.display();
	l1.delete_pos(3);
	l1.display();
}

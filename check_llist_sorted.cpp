#include<iostream>
 
 
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
	public:
	node* head;
	void insert_begin(int data);
	void display();
	bool sortOrNot();
	
	
};

bool linkedlist::sortOrNot()
{
	node *p;
	int min=INT_MIN;
	p=head;
	while(p!=NULL)
	{
		if(p->data < min)
		{
			return 0;
		}
		else
		{
			min=p->data;
		}
		
		
		p=p->next;
	}
	return 1;
}
void linkedlist::insert_begin(int data)
{
	node* temp=new node();
	temp->data=data;
	temp->next=head;
	head=temp;
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
	//
	linkedlist l1;
	l1.insert_begin(77);
	l1.insert_begin(18);
	l1.insert_begin(9);
	l1.insert_begin(4);
	l1.insert_begin(3);
	l1.insert_begin(2);
	l1.insert_begin(1);
	l1.display();
	cout<<endl;
	if(l1.sortOrNot())
	{
		cout<<" linked list is sorted"<<endl;
		
	}
	else
	{
		cout<<"linked list is not sorted"<<endl;
	}
	
}

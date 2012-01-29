
#include <iostream>
#include <string.h>
using namespace::std;
class node 
{
private:
//int data;

public:
node* Left;
node* Right;
int data;

node() { data=0;Left=NULL;Right=NULL;}
void setdata(int d)
{ data=d;}

int getdata()
{return data; }

};


class list
{
public:
	node* head, * tail;
	
public:
	list()
	{
		head = NULL; tail = NULL;
	}
	
	void addnode(int data)
	{
		node* n = new node();
		n->setdata(data);
		if (head == NULL)
		{ head = n; tail = n;}
		else
		{
			n->Left = tail;
			tail->Right = n;
			tail=n;			
		}
			
	}
	
	void displaynode()
	{
		node* n = head;
		while(n!=NULL)
		{
			cout << n->getdata() << " ";
			n=n->Right;
		}
	}
	
	void reverse()
	{
		
		node* n1 = head;
		node* n2 = n1;
		node* temp1, *temp2;
				while(n1)
				{
					temp1=n1->Right;
					temp2=n1->Left;
					n1->Left=temp1;
					n1->Right=temp2;
					n2=n1;
					n1 = temp1;					
				}
				head = n2;
	}
	
	void revlist()
	{
		node* n = head;
		node* prev = NULL;
		node* temp = NULL;
		
		while(n)
		{
			temp = n->Right;
			n->Left = temp;
			n->Right = prev;
			prev=n;
			n=temp;			
		}
		head = prev;
	}
};

node* getmiddle(node* h)
{
	if(!h)
		return h;
	node* f = h;
	node* s = h;
	
	while((f->Right!=NULL) && (f->Right->Right != NULL))
	{
		s = s->Right;
		f=f->Right->Right;
	}
	return s;
}

node* merge(node* a, node* b)
{
	node* d = NULL;
	node* r;
	node* p = NULL;

	
	while((a!=NULL) && ( b!=NULL))
	{
		node* t = new node();

        if(a->data > b->data)
        {
        	t=b;
        	b=b->Right;
        }
        else
        {
        	t=a;
        	a=a->Right;
        }
        if(!d)
        {
        	d=t;
        	r=d;
        	p=d;
        	
        }
        else
        {
        	p=d;
        	d->Right = t;
        	d=d->Right;
        	d->Left = p;
        }
	}
	while(b !=NULL)
	{
		node* t = new node();
		t=b;
		p=d;
    	d->Right = t;
    	d=d->Right;
    	d->Left = p;
    	b=b->Right;		
	}
	
	while(a != NULL)
	{
		node* t = new node();
		t=a;
		p=d;
    	d->Right = t;
    	d=d->Right;
    	d->Left = p;
    	a=a->Right;		
		
	}
	
	return r;
	
}


node* mergesort(node* h)
{
	if ( (h==NULL) || (h->Right == NULL))
	{
		return h;
	}
	node* m = getmiddle(h);
	node* half = m->Right;
	m->Right = NULL;
	
	return (merge(mergesort(h), mergesort(half)));
	
}

int main()
{
	int i=0, j=0;
	list l;
	
	cout << "Enter data \n";
	while(i<6)
	{
		cin >> j;
		l.addnode(j);
		i++;
	}
	l.displaynode();
	
	//l.revlist();
	//cout << " \n";
	//l.displaynode();
	
	node* n = mergesort(l.head);
	cout << "\n\n";
	
		while(n!=NULL)
		{
			cout << n->getdata() << " ";
			n=n->Right;
		}
}

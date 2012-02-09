//convert integer to character.
#include <iostream>
#include <exception>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <fstream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	
	node()
	{
		data=0;
		left=NULL;
		right=NULL;
	}
	node(int d)
	{
		data = d;
		left=NULL;
		right=NULL;
	}
};

class btree
{
public:
	node* root;
	static node* parent;
	
	btree()
	{
		root = NULL;
	}
	
	node*  insert(node* n, int data)
	{
		node* t = new node(data);
		if(n == NULL)
		{
			return t;
		}
		else
		{
			if(data > n->data)
			{
				n->right = insert(n->right, data);
			}
			else
			{
				n->left = insert(n->left,data);
			}
		}
		return n;
	}
	
	void display(node* n)
	{
		if(n)
		{
			display(n->left);
			cout << n->data << " " ;
			display(n->right);
					
		}
	}
	node* findnode(node* n, node* p, int data)
	{
		parent = p;
		if(n->data == data)
		{
			return n;
		}
		else if(data > n->data)
		{
			findnode(n->right, n,data);
		}
		else
		{
			findnode(n->left,n, data);
		}
			
	}
	void deletenode(int data)
	{
		node* child;
	    node* fnode=root;
		node* n = findnode(root, root, data);
		node* delnode=n;
		
		if(n == NULL)
		{
			return;
		}
		
		if( (n->left) && (n->right))
		{
			child=n->right;
			parent = n;
			node* prev = n;
			
			while(child)
			{
				parent=prev;
				delnode = child;
				child = child->left;
				prev=child;
			}
			
			n->data = delnode->data;
			n=delnode;
		}
		
		if(n->right)
		{			
			if(parent->right==n)
				parent->right = n->right;
			else
				parent->left = n->right;
			
			delete n;
			n=NULL;
			return;
		}
		if(n->left)
		{
			if(parent->right == n)
				parent->right = n->left;
			else
				parent->left = n->left;
			
			delete n;
			n=NULL;
			return;
		}
		if( (n->left == NULL) && (n->right == NULL))
		{
			if( (parent->left) == n)
				parent->left = NULL;
			else
				parent->right=NULL;
			
			delete n;
			n=NULL;			
		}		
	}
};

node* btree::parent = NULL;

int main()
{
btree b;
b.root = b.insert(b.root,10);
b.insert(b.root,13);
b.insert(b.root,7);
b.insert(b.root,8);
b.insert(b.root,15);
b.insert(b.root,4);
b.insert(b.root,21);
b.insert(b.root,6);
b.insert(b.root,12);
b.insert(b.root,11);
b.insert(b.root,24);
b.insert(b.root,20);

b.display(b.root);

cout << "\n\n";

b.deletenode(15);

b.display(b.root);
	
}

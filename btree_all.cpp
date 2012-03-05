//convert integer to character.
#include <iostream>
#include <exception>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <fstream>
#include <deque>
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
	
	~node()
	{
		left=NULL;
		right=NULL;
	}
};

class btree
{
public:
	node* root;
	static int lastdata;

	
	btree()
	{
		root = NULL;
	}
	
	void insert(int data)
	{
		node* temp = new node(data);
		
		if(root == NULL)
		{
			root = temp;
		}
		else
		{
			insertnode(temp,root);
		}
	}
	
	void insertnode(node* n, node* r)
	{
		if(n->data > r->data)
		{
			if(r->right == NULL)
				r->right = n;
			else						
			insertnode(n,r->right);
		}
		else
		{
			if(r->left == NULL)
				r->left = n;
			else
				insertnode(n,r->left);
		}	
	}
	
	
	void display(node* n)
	{
		if(n==NULL)
			return;
		display(n->left);
		cout << n->data << "   " ;
		display(n->right);
	}
	
	node* search(node* n, int data)
	{
		if(n)
		{
			if(n->data == data)
				return n;
			else
			{
				if(data < n->data)
					search(n->left, data);
				else
					search(n->right,data);						
			}
		}
		else
			return n;		
	}
	
	node* treemin(node* n)
	{
		if(n== NULL)
			return n;
		
	    while(n->left != NULL)
	    	n=n->left;
	    
	    return n;
	}
	
	node* treemax(node* n)
	{
		if(n == NULL)
			return n;
		
		while(n->right)
			n = n->right;
		return n;
	}
	
	void setlastdata(int data)
	{
		lastdata = data-1;
	}
	
	bool isBST(node* n)
	{		
		if(n==NULL)
			return true;
		
		isBST(n->left);
		
		
		if(lastdata < n->data)
			lastdata = n->data;
		else
		{
			cout << "Not BST\n";
			return false;
		}
		
		isBST(n->right);
		
		return true;	
		
	}
	
	void alter(int data)
	{
		node* n= root;
		node* t = new node(data);
		root = t;
		t->left = n;
		
	}
	
	int  maxheight(node* n)
	{
		if((n == NULL)|| (n->left == NULL && n->right == NULL))
			return 0;
		int lheight = maxheight(n->left);
		cout << lheight << " lheight " << n->data << "\n";
		int rheight = maxheight(n->right);
		cout << lheight << " rheight  " << n->data << "\n";
		
		if(lheight > rheight)
			return lheight+1;
		else
			return rheight+1;
	}
	
	int minheight(node* n)
	{
		if(n == NULL)
			return 0;
		
		int lheight = minheight(n->left);
		cout << lheight << " lheight " << n->data << "\n";
		int rheight = minheight(n->right);
		cout << lheight << " rheight  " << n->data << "\n";
		
		if(lheight < rheight)
			return lheight+1;
		else
			return rheight+1;
	}
	int treesize(node* n)
	{
		if(n == NULL)
			return 0;
		int lheight = treesize(n->left);
		int rheight = treesize(n->right);
		
		return (lheight+rheight+1);
	}
	
	void isbalanced(node* n)
	{
		if(maxheight(n) - minheight(n) <= 1)
				cout << "Balanced\n";
		else
			cout << "Not Balanced\n";
	}
	
	node* findparent(node* n, int data)
	{
		node* parent = n;
		bool found = false;
		
		while(!found)
		{
			if(data == n->data)
			{
				found = true;
			}
			else if(data > n->data)
			{
				parent = n;
				n = n->right;
			}
			else
			{
				parent = n;
				n= n->left;
			}		
			if(n==NULL)
			{
				found = true;
				parent=NULL;
			}
		}
		return parent;
		
	}
	
	node* inordersuccessor(node* n)
	{

		if(n == NULL)
			return n;
		
		if(n->right)
		{
			return treemin(n->right);
		}		
		
		node* succ = findparent(root, n->data);
		
		while(succ && (n == succ->right))
		{
			n= succ;
			succ = findparent(root, succ->data);
		}
		return succ;
	}

	
	
	node* inorderpredecessor(node* n)
	{
		node* prs;
		
		if(n->left)
		{
			return treemax(n->left);
		}
		
		prs = findparent(root,n->data);
		
		while(prs && (n == prs->left))
		{
			n = prs;
			prs = findparent(root,prs->data);
		}
		return prs;		
	}
	
	node* lowestcommonans(node* n1, node* n2)
	{
		
		if( (root->left == n1) || (root->right == n1) || ( root->left == n2) || ( root->right == n2))
			return root;
		bool found = false;
		
		node* temp1=NULL;
		node* temp2;
		
		if((n1->data < root->data)  )
		{
			
			temp1 = findparent(root, n1->data);
			
			while(!found)
			{
				temp2 = search(temp1,n2->data);
				
				if(temp2)
				{
					found = true;					
				}
				else
				{
					n1 = temp1;
					temp1 = findparent(root, n1->data);
				}				
			}
		}
		
		return temp1;
	}
	
	void clear(node* n)
	{
		if(n!= NULL)
		{
		clear(n->left);
		clear(n->right);
		
		cout << n->data << "  ";
		delete n;
		//n=NULL;
		}
	}
	
	
	void printallpath(node* n)
	{
		int path[100];
		
		findallpath(n,path,0);
	}
	
	void findallpath(node* n,int path[], int len)
	{
		if(n==NULL)
			return ;
		path[len++] = n->data;
		
		if((n->left == NULL) && (n->right == NULL))
		{
			printpath(path,len);
		}else
		{
			findallpath(n->left,path,len);
			findallpath(n->right,path,len);
		}

	}
	
	void printpath(int path[], int len)
	{
		for(int i=0;i<len;i++)
			cout << path[i] << "  " ;
	}
	
	
	bool issubtree(node* n)
	{
		bool found = false;
		node* t = root;
		while(!found )
		{
			if(t == NULL)
			{
				return false;
			}
			if(t->data == n->data)
			{
				found = true;
			}
			else
			{
				if(n->data > t->data)
				{
					t=t->right;
				}
				else
				{
					t=t->left;
				}
			}
		}
		
		if(found)
		{
			return (matchtree(n,t));
			//return true;
		}
		else
		{
			return false;
		}
	}
	
	bool matchtree(node* n, node* t)
	{
		if((n==NULL) && (t==NULL))
			return true;
		if(t == NULL)
			return false;
		
		if(n->data == t->data)
		{
			matchtree(n->left,t->left);
			matchtree(n->right,t->right);					
		}
		else
		{
			return false;
		}
		return true;
	}
};

int btree::lastdata  =0;

int main()
{
	btree* b = new btree;
	int data;
	cout << "Enter 10 numbers \n";
	
	for (int i=0;i<9;i++)
	{
		cin >> data;
		
		b->insert(data);			
	}
	
	b->display(b->root);
	
	cout << "\n\n";
	
	//node* n = b->t(b->root);
	
	//b->setlastdata(n->data);
	
	//b->alter(100);
	
	//cout << b->isBST(b->root);
	
	//cout << "size is : " << b->treesize(b->root);
	
	//b->isbalanced(b->root);
	
	//node* n = b->treemax(b->root);
	
	//node* n = b->findparent(b->root, 43);
	
	node* n = b->search(b->root, 15);
	
	//cout << n->data;
	
	//node* n1 = b->inordersuccessor(n);
	
	//node* n1 = b->search(b->root, 43);
	
	//node* n2 = b->lowestcommonans(n,n1);
	
	cout <<"\n\n";;
	
	//b->printallpath(b->root);
	
	//b->clear(b->root);
	
	node* n1 = new node(100);
	//node* n1 = b->search(b->root, 30);
	
	bool t = b->issubtree(n1);
	
	cout << t;
	
}
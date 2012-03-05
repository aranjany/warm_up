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

class hashentry
{
private:
	int value;
	int key;
	
public:
	hashentry(int key, int value)
	{
		this->key =key;
		this->value = value;
	}
	
	hashentry()
	{
		key = 0;
		value=0;
	}
	
	int getvalue()
	{
		return value;
	}
	
	int getkey()
	{
		return key;
	}
};

const int TSIZE = 128;

class hashmap
{
	hashentry **table;
	
public:
	hashmap()
	{
		table = new hashentry*[TSIZE];
		for(int i=0;i<TSIZE;i++)
		{
			table[i] = NULL;
		}
	}
	
	void put(int key, int value)
	{
		int hash = (key%TSIZE);
		
		while(( table[hash] != NULL) && (table[hash]->getkey() != key))
		{
			hash= ((hash+1)%TSIZE);
		}
		
		if(table[hash] != NULL)
		{
			delete table[hash];
		}
		
		table[hash] = new hashentry(key,value);

	}
	
	int  get(int key)
	{
		int hash = (key%TSIZE);
		
		while((table[hash] != NULL) && (table[hash]->getkey() != key))
		{
			hash = (hash+1)%TSIZE;
		}
		
		if(table[hash] == NULL)
			return -1;
		else
			return (table[hash]->getvalue());
		
	}
	
	~hashmap()
	{
		for(int i=0;i<TSIZE;i++)
		{
			if(table[i] != NULL)
				delete [] table[i];
		}
		delete [] table;
	}
};

int main()
{
	
	hashmap* h = new hashmap;
	
	h->put(10,200);
	h->put(20,200);
	h->put(128,300);
	h->put(1280,250);
	h->put(25,350);
	//h->put(18,800);
	
	cout << "\n\n";
	cout << h->get(1280);
			
	
	
}
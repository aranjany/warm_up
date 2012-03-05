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
#include <stack>
#include <set>
using namespace std;



void check(string s1)
{
	stack<string> st;
	
	
	int i=0;
	string t;
	char space=' ';
	
	while(s1[i] !='\0')
	{
		t+=s1[i];
		if(s1[i] == space)
		{
			st.push(t);
			t="";
		}
		i++;
	}
	t+=space;
	st.push(t);
	
	while(!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	
}

void search(string s1)
{
	
	string space(" ");;
	
	size_t pos=1;
	string sub;
	string rest;
	int i=0;
	
	map<string,int> mymap;
	pair<map<string,int>::iterator,bool> ret;
	map<string,int>::iterator it;
	
	multimap<int,string> mymap1;
	pair<multimap<int,string>::iterator,bool> ret1;
	multimap<int,string>::reverse_iterator it1;
	
	/*multiset<string> myset;
	pair1<multiset<string>::iterator,bool>  ret;
	multiset<string>::iterator it1;*/
	
	
	

	
	/*while(pos != 0)
	{
		pos = s1.find(space);
		//cout << pos << " ";
		sub=s1.substr(0,pos+1);
		cout << sub << "\n";
		
		ret = myset.insert(sub);
		
		if(ret.second == false)
		{
			cout << sub << " repeat \n";
		}
		pos++;
		s1=s1.substr(pos);
	}
	
	for(it = myset.begin(); it != myset.end(); it++)
	{
		cout << *it;
	}*/
	
	while(pos != 0)
	{
		pos = s1.find(space);
		sub = s1.substr(0,pos);
		
		ret = mymap.insert(pair<string,int> (sub,1));
		if(ret.second == false)
		{
			ret.first->second++;
		}
		pos++;
		s1=s1.substr(pos);
		
	}
	
	for(it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << (*it).first << " => "  << (*it).second << "\n";
		mymap1.insert(pair<int,string>((*it).second, (*it).first));
		
	}
	
	for(it1 = mymap1.rbegin(); it1 != mymap1.rend(); it1++)
	{
		cout << (*it1).first << " => "  << (*it1).second << "\n";
			
	}
}

int main()
{
	string s1 = "This world is full of energy and energy and energy is my full";

	search(s1);
}
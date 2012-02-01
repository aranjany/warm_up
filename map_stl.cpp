//convert integer to character.
#include <iostream>
#include <exception>
#include <string.h>
#include <vector>
#include <map>
#include <time.h>
using namespace std;


int main()
{
	map<time_t,int> detail;
	map<int,time_t> matter;
	
	time_t time1;
	time(&time1);
	int val;
	int i=0;
	map<time_t,int>::iterator it1;
	map<int,time_t>::iterator it2;
	
	map<time_t,int>::iterator dt1;
	map<int,time_t>::iterator dt2;
	
	while(i<7)
	{
		cout << "Enter value\n";
		cin >> val;
		
		it2= matter.find(val);
		dt2=it2;
		if((*it2).first == val)
		{
			int v = (*it2).first;
			time_t t = (*it2).second;
						
			//cout << "Exist \n";
			it1 = detail.find(t);
			//cout << (*it1).first << "\n";
			detail.erase(it1);
			matter.erase(it2);
			

			it1=detail.begin();
			it2=matter.begin();
			
			detail.insert(it1, pair<time_t,int>(time1,v));
			matter.insert(it2, pair<int,time_t>(v,time1));
			
			
		}
		else
		{		
			detail.begin();
			matter.begin();
			detail[time1] = val;
			matter[val]=time1;	
		}
		i++;
		time(&time1);

	}

	
	for(it1=detail.begin(); it1 != detail.end(); it1++)
	{
		cout << (*it1).first << "  => " << (*it1).second << "\n";

		cout << "\n\n";
	}
	
	for(it2=matter.begin();  it2!=matter.end();it2++)
		{
			cout << (*it2).first << "  => " << (*it2).second << "\n";
			cout << "\n\n";
		}
}
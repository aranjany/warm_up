//convert integer to character.
#include <iostream>
#include <exception>
#include <string.h>
#include <vector>
using namespace std;

class sCback
{
public:
	
    void display(char* data)
	{
		cout << "data is \n";
		cout << data << "\n";
	}
	
	static void wrapper(void* sc, char* str)
	{
		sCback* pt=(sCback*)sc;
		pt->display(str);
	}
	
	
};

void doProcess(void* pt, void (*ptfn) (void* pt, char* data))
	{
		
		char* details ="No details as of now";
		
		ptfn(pt,details);
	}
			
int main()
{
	sCback *s = new sCback;;
    doProcess((void*)&s, sCback::wrapper);
}
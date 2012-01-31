//convert integer to character.
#include <iostream>
#include <exception>
#include <string.h>
#include <vector>
#include <map>
using namespace std;


void checkdigit(char* data)
{
	int len = strlen(data);
	
	int i=0;
	bool dot = false;
	bool number = false;
	while(i<len)
	{
		if((data[i] >='0' ) && (data[i] <='9'))
		{
			number=true;
			
		}
		else if( (data[i] == '.') && (dot == false))
		{
			dot = true;
		}
		else if( (data[i] == '.') && (dot == true))
		{
			cout << "Not Number";
			number=false;
			break;
		}
		else
		{
			cout << "Not Number";
			number=false;
			break;
		}
		i++;
	}
	if(number)
		cout << "Number \n";
}
			
int main()
{
char* data = "12..35";
checkdigit(data);
}
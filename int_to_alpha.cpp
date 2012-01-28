//convert integer to character.
#include <iostream>
#include <exception>
#include <string.h>
#include <malloc.h>
using namespace std;
void reverse(char* arr)
{
	int len = strlen(arr);
	int i=0;
	
	while(i<len)
	{
		char t = arr[i];
		arr[i] = arr[len-1];
		arr[len-1] = t;
		i++;len--;
	}
		cout << arr;
}

void  convert(int i)
{
	char arr[1024];
	int t=i;
	
	if (i==0)
	{
		arr[0]='0';
		arr[1]='\0';
	}
	else
	{
		int x=0;
		while(t)
		{
			char y = t % 10 + '0';
			arr[x]=y;
			t=t/10;
			x++;
		}
		arr[x]='\0';
	}

reverse(arr);

	
}
int main()
{
	int i=12345;
	convert(i);
}
#include <iostream>
#include <string>

const char *FILENAME="test.dat";

int testMalloc(char *dumpname)
{
	char *test = NULL;
	if ((test = (char *)malloc(sizeof(char) * 128)) == NULL)
	{
		return 1;
	}; 

	return 0;
}

int main()
{
}


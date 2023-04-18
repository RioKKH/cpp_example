#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (strcmp(argv[1], "foo") == 0)
    {
        printf("foo!\n");
    }
    else 
    {
        printf("hello\n");
    }

    return 0;
}

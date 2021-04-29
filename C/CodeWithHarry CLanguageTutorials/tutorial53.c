#include <stdio.h>

int main()
{
    int a = 34;
    char * str = "HI ASHISH";
    int *ptr = NULL;
    if (ptr != NULL)
    {
        printf("The address of a is %d\n", ptr);
    }
    else
    {
        printf("The pointer is a null pointer and cannot be dereferenced\n");
    }
    printf("%s\n", str);
    return 0;
}
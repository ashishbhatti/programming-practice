/*
 PROBLEM
You have to create a command line utility to 
add/subtract/divide/multiply two numbers

First command line argument of your c program must be the operation.
The next arguments being the two numbers.

For Exmaple:
>>Command.c add 45 4
>>49

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a;
    int b;

    if (argc == 4)
    {
        sscanf(argv[2], "%d", &a);
        sscanf(argv[3], "%d", &b);

        if (!strcmp(argv[1], "add"))
        {
            printf("%d\n", a + b);
        }
        else if (!strcmp(argv[1], "sub"))
        {

            printf("%d\n", a - b);
        }
        else if (!strcmp(argv[1], "mul"))
        {

            printf("%d\n", a * b);
        }
        else if (!strcmp(argv[1], "div"))
        {

            printf("%d\n", a / b);
        }
    }
    else
    {
        printf("Correct arguments: operation look like: add sub mul div, then followed by two numbers\n");
        printf("Give correct arguments\n");
    }

    return 0;
}

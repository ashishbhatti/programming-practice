#include <stdio.h>
#include <string.h>

int sum(int a, int b)
{
    return a + b;
}

void greetHelloAndExecute(int (*fptr)(int, int))
{
    printf("Hello User\n");
    printf("The sum of 5 and 7 is %d\n", fptr(5, 7));
}

void greetGmAndExecute (int (*fptr)(int, int))
{
    printf("Good Morning User\n");
    printf("The sum of 5 and 7 is %d\n", fptr(5, 7));
}

void greetGaAndExecute (int (*fptr)(int, int))
{
    printf("Good Afternoon User\n");
    printf("The mean of 5 and 7 is %d\n", fptr(5, 7) / 2);
}

void greetGeAndExecute (int (*fptr)(int, int))
{
    printf("Good Evening User\n");
    printf("The mean of 5 and 7 is %d\n", fptr(5, 7) / 2);
}

int main()
{
    int (*ptr)(int, int);
    ptr = sum;
    greetGeAndExecute(ptr);
    return 0;
}
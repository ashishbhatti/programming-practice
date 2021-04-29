#include <stdio.h>
//#include "temp.c"


int myfunc(int a, int b)
{
    //auto int sum;
    extern int sum;
    //sum = a+b;
    return sum;
}

int sum = 34;
int main()
{
    // Declaration - Telling the compiler about the variable (No space reserved)
    // Definition - DEclaration + space reservation

    int sum = myfunc(3,5);

    printf("The sum is %d\n", sum);

    return 0;
}
//Implementation of dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h> // calloc, amlloc defined in this

int main()
{
    /*
    //use malloc
    int *ptr;
    int n;
    printf("Enter the size of array you want to create\n");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("The value at index %d of this array is %d\n", i, ptr[i]);
        //scanf("%d", &ptr[i]);
    }
    */

   

    //use calloc
    int *ptr;
    int n;
    printf("Enter the size of array you want to create\n");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("The value at index %d of this array is %d\n", i, ptr[i]);
        //scanf("%d", &ptr[i]);
    }
    

    //use realloc
    //int *ptr;
    //int n;
    printf("Enter the size of new array you want to create\n");
    scanf("%d", &n);

    ptr = (int *)realloc(ptr, n* sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("The new value at index %d of this array is %d\n", i, ptr[i]);
        //scanf("%d", &ptr[i]);
    }

    free(ptr);

    return 0;
}
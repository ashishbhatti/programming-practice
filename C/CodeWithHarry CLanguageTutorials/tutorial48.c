//Employee Manager 

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int employees = 3;
    int n;
    char *ptr;

    for (int i = 0; i < employees; i++)
    {
        printf("Employee %d \n",i);

        printf("Enter numbers of characters in your id \n",i);
        scanf("%d", &n);

        ptr = (char*)malloc((n+1)*sizeof(char));

        printf("Enter your id \n");
        scanf("%s",ptr);
        printf("Id of Employee %d is: %s\n", i,ptr);
        free(ptr);

    }

    return 0;
}
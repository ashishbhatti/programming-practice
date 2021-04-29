#include <stdio.h>

void arrayRev(int arr[])
{
    int temp;
    for (int i = 0; i < 7 / 2; i++)
    {
        //swap item i with item 6-i
        temp = arr[i];
        arr[i] = arr[6 - i];
        arr[6 - i] = temp;
    }
}

void arrayPrint(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 67};
    printf("Before Reversing the array\n");
    arrayPrint(arr);
    arrayRev(arr);

    printf("\nAfter Reversing the array\n");
    arrayPrint(arr);

    return 0;
}
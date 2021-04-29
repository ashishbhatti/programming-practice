/*matrix multiplication
*/

#include <stdio.h>
#include <stdlib.h>

void matrixMultiply(int *mat1, int m1, int n1, int *mat2, int m2, int n2, int *ptr)
{
    /*
    Multiply two matrices
    No check is performed if n1 and m2 are equal or not. Please check it before calling this function
    ptr is the pointer of the heap array where result matrix is to be stored.
    Logic : Aij = (sum from k = 0 to n1-1 or m2-1) (aik*bkj)
    */
    int roff1 = n1;
    int roff2 = n2;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            for (int k = 0; k < n1; k++)
            {
                *(ptr + j + i * roff2) = *(ptr + j + i * roff2) + (*(mat1 + k + i * roff1)) * (*(mat2 + j + k * (roff2)));
            }
        }
    }
    return;
}

void printmat(int *mat, int m, int n)
{
    // Prints the matrix with decent formatting
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d    ", *(mat + i * n + j));
        }

        printf("\n");
    }
    printf("\n");
}

void matin(int *mat, int m, int n)
{
    //Takes input of the matrix elements.
    //One row at a time.
    printf("Enter matrices values row-wise as a1 b1 a2 b2\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (mat + i * n + j));
            getchar();
        }
    }
}

int main()
{
    int m1, n1, m2, n2;

    printf("Enter dimension of Matrix 1 as m n:\n");
    scanf("%d %d", &m1, &n1);
    getchar();

    printf("Enter dimension of Matrix 2 as m n:\n");
    scanf("%d %d", &m2, &n2);
    getchar();

    if (n1 != m2)
    {
        printf("Dimensions of matrices invalid for multiplication\n");
        return 0;
    }

    int *mat1 = (int *)malloc((m1 * n1) * sizeof(int));
    int *mat2 = (int *)malloc((m1 * n1) * sizeof(int));

    matin(mat1, m1, n1);
    matin(mat2, m2, n2);

    int *ptr = NULL;

    ptr = (int *)calloc((m1 * n2), sizeof(int));
    if (ptr != NULL)
    {
        printf("Multiplication possible\n");
        matrixMultiply(mat1, m1, n1, mat2, m2, n2, ptr);
    }
    else
    {
        printf("Memory unavailable in heap\n");
    }

    printmat(mat1, m1, n1);
    printmat(mat2, m2, n2);

    if (ptr != NULL)
    {
        printmat(ptr, m1, n2);
        free(ptr);
    }

    free(mat1);
    free(mat2);

    return 0;
}
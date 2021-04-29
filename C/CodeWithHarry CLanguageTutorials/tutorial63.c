#include <stdio.h>
#include <string.h>

int strPalindrome(char str[])
{
    
    char new[70];
    strcpy (new,str);
    if (strcmp(str,strrev(new)))
    {
        //printf("%s",new);
        return 0;
    }
    else
    {
        //printf("%s",new);
        return 1;
    }
}

int isPalindrome(long int num)
{
    int n = num;
    //printf("%ld\n",n);
    int new = 0;
    int i = 0;
    while (n > 0)
    {
        new = (new * 10 + n % 10);
        n = n / 10;
        //printf("%d\n",new);
        i++;
    }
    if (i >= 10)
    {
        printf("Error: Integer Overflow, Integer should be less than 10 digits.\n");
        return -1;
    }
    else if (num == new)
    {
        //printf("returning 0\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    /*
    //Integer Palindrome
    int number;
    printf("Enter a number to check whether it is a palindrome or not\n");
    scanf("%d", &number);
    //Your task is to implement this function
    if (isPalindrome(number))
    {
        printf("This number is a palindrome\n");
    }
    else
    {
        printf("This number is not a palindrome\n");
    }
    */

    //String Palindrome
    char string[64];
    printf("Enter a string to check whether it is a palindrome or not\n");
    scanf("%s", &string);
    //Your task is to implement this function
    if (strPalindrome(string))
    {
        printf("This string is a palindrome\n");
    }
    else
    {
        printf("This string is not a palindrome\n");
    }

    return 0;
}
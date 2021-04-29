#include <stdio.h>
#include <string.h>

/* MY SOLUTION TO THE PROBLEM 
void parser(char arr[], int len)
{
    // "<h1> This is a string <\h1>"
    //Calculate length of arr, is null character included in length?

    //use for loop to find first iteration of '>'
    int a; // a is the index where '>' or a "> " is detected
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == '>')
        {
            if (arr[i + 1] == ' ')
            {
                a = i + 1;
                break;
            }
            else
            {
                a = i;
                break;
            }
        }
    }

    //estimate from length the range of characters to print
    for (int j = a + 1; j < len - (a + 3); j++) // (a+1) is for the tag and 2 more for two backslashes
    {
        printf("%c", arr[j]);
    }
}
*/

void parser(char *str)
{
    int in = 0; //Variable to track whether we are inside the tag
    int index = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (str[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';

    //Remove the trailing spaces from the beginning
    while (str[0] == ' ')
    {
        //shift he string to the left
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
    }
    //Remove the trailing spaces from the end
    while (str[strlen(str) - 1] == ' ')
    {
        str[strlen(str) - 1] = '\0';
    }
}

int main()
{
    char str[] = "<h1>    This is a string    </h1>";
    int len = sizeof(str) / sizeof(char);
    printf("%d %d\n", len, strlen(str));
    parser(str);
    printf("The parsed string is ~~%s~~", str);
    return 0;
}
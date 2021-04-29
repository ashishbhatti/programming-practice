#include <stdio.h>
#include <string.h>

int main()
{
    //char s1[] = "harry";
    //char s2[] = "ravi";
    //char s3[54];
//
    //printf("The strcmp for s1,s2 returned %d \n", strcmp(s1, s2));

    // puts(strcat(s1,s2));
    //printf("The length of s1 is %d\n", strlen(s1));
    //printf("The length of s2 is %d\n", strlen(s2));
    //printf("The reversed string of s1 is :\n");
    //puts(strrev(s1));

    //strcpy(s3, strcat(s1, s2));
    //puts(s3);


    /* Excercise to take two strings as input and 
    then concatinate them as :
    st1 is a friend of str2    */

    char str1[20];
    char str2[20];

    printf("Enter first name : \n");
    gets(str1);
    printf("Enter second name : \n");
    gets(str2);

    char str3 [] = "is a friend of  ";
    char str4[60];
    strcpy(str4,strcat(str1,str3));
    strcpy(str4,strcat(str4,str2));
    
    puts(str4); 



    return 0;
}
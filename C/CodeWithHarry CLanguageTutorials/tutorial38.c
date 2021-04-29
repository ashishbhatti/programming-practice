#include <stdio.h>

typedef struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
} std;

int main()
{
    //int *a, b; // a is a pointer but b is an integer
    typedef int *intPointer;
    intPointer a, b;
    int c = 89;
    a = &c;
    b = &c;

    //struct Student s1, s2;
    //std s1, s2;
    //s1.id = 56;
    //s2.id = 86;
    //printf("Value of s1's Id is %d\n", s1.id);
    //printf("Value of s2's Id is %d\n", s2.id);

    // syntax typedef
    //typedef <previous_name> <alias_name>
    //typedef unsigned long ul;
    //typedef int integer;
    //ul l1, l2, l3;
    //integer a = 4;
    ////int b = 5;
    //printf("Value of a is %d\n", a);

    return 0;
}
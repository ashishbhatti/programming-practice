#include <stdio.h>
#include <string.h>

union Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
};

int main()
{
    union Student s1;

    strcpy(s1.name, "Harry");
    s1.fav_char = 'u';
    s1.marks = 45;
    s1.id = 1;

    printf("The id is %d\n", s1.id);
    printf("The marks are %d\n", s1.marks);
    printf("The fav_char is %c\n", s1.fav_char);
    printf("The name is %s\n", s1.name);

    printf("The size is %d bytes\n", sizeof(s1));
    printf("The size is %d bytes\n", sizeof(s1.id));
    printf("The size is %d bytes\n", sizeof(s1.marks));
    printf("The size is %d bytes\n", sizeof(s1.fav_char));
    printf("The size is %d bytes\n", sizeof(s1.name));

    return 0;
}
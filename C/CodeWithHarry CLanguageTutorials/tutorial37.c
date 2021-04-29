#include <stdio.h>
#include <string.h>

/*  //Understanding part of lecture
struct student {
    //creating a new data-type student
    int id;
    int marks;
    char fav_char;
} s1,s2,s3;


struct Employee
{
    // declaring a new data type
    int id;
    char name[53];
    float marks;
};  // haven't declared a structure variable yet

struct Employee e1, e2;


struct Employee1 
{
    // declaring a new data type
    int id;
    char name[53];
    float marks;
} e3, e4 ;  //declare variables of this new data type



struct Employee
{
    int id;
    float marks;
    //int mace;
};
*/

struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
} harry, ravi, shubham;

//struct Student harry, ravi, shubham; //global variable

void print()
{
    printf("%s", harry.name);
}

int main()
{

    //struct Employee e1;
    //e1.id = 12;
    //e1.marks = 34.12;

    //struct Employee e1 = {12,34.12};

    // struct Student harry, ravi, shubham;  //local variable
    harry.id = 1;
    ravi.id = 2;
    shubham.id = 3;
    harry.marks = 66;
    shubham.marks = 46;
    ravi.marks = 466;
    harry.fav_char = 'p';
    ravi.fav_char = 'y';
    shubham.fav_char = 'o';
    strcpy(harry.name, "Harry Potter student of the year");
    strcpy(shubham.name, "Shubham Kumar");
    //printf("Harry got %d marks\n", harry.marks);
    ////printf("%d",(float)66);
    //printf("Harry's name is: %s\n", harry.name);
    //printf("Shubham  got %d marks\n", shubham.marks);
    //printf("Shubham's name is: %s\n",shubham.name);

    print();

    /*
    //Quick quiz : print info of a given student
    struct Student alice = {16, 98, 'a'};
    //printf("Enter the name of a student:");
    //scanf("%s",&stu.);
    printf("ID of alice is %d\n", alice.id);
    printf("MArks of alice are %d\n", alice.marks);
    printf("Fav character of alice is %c\n", alice.fav_char);
    */

    return 0;
}
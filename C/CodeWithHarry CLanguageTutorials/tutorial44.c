/* PROBLEM

You manage a travel agency and you want your n drivers
to input their details:
1. Name
2. Driving License No.
3. Route
4. Kms driven with you

All above are strings

Program should take n as input
or take n=3 for simplicity
ANd then the n drivers input their 
details one by one.

Program should print the details of the drivers in a
beautiful fashion.

Solve using structure.
*/

//SOLUTION

#include <stdio.h>
#include <string.h>

struct driver
{ // structure to hold details of driver
    int sno;
    char name[20];
    char dl[20];
    char route[50];
    char distance[10];
};

void print_d(struct driver d1)
{ //prints driver details in a presentable manner
    //printf("Details of Driver %d", sno);
    printf("Details of the driver %d are as follows ~\n",d1.sno);
    printf("Name: %s \n", d1.name);
    printf("Driving License No: %s \n", d1.dl);
    printf("Route: %s \n", d1.route);
    printf("Distance: %s \n", d1.distance);
    printf("\n \n");

}

int main()
{
    int n = 3;
    //scanf("%d", &n);
    printf("%d\n", n);

    //struct driver d1;

    struct driver list[n];

    for (int i = 0; i < 3; i++)
    {
        list[i].sno = i+1;
        printf("Enter details of driver %d\n", i + 1);
        printf("Name: ");
        gets((list[i].name));
        printf("DL No: ");
        gets(list[i].dl);
        printf("Route: ");
        gets(list[i].route);
        printf("Distance: ");
        gets(list[i].distance);
        printf("\n");

    }

    for (int i = 0; i < 3; i++)
    {    
        print_d(list[i]);
    }






    return 0;
}
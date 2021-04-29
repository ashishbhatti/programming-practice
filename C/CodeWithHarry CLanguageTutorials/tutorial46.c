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

#include <stdio.h>
#include <string.h>

struct Driver
{
    char name[34];
    char dlNo[45];
    char route[47];
    int kms;
};

int main()
{
    struct Driver d1, d2, d3;
    printf("Enter the details of the drivers \n");

    printf("Enter the name of Driver 1\n");
    scanf("%s", &d1.name);
    printf("Enter the dlno of Driver 1\n");
    scanf("%s", &d1.dlNo);
    printf("Enter the route of Driver 1\n");
    scanf("%s", &d1.route);
    printf("Enter the no of kms of Driver 1\n");
    scanf("%d", &d1.kms);
    printf("\n");

    printf("Enter the name of Driver 2\n");
    scanf("%s", &d2.name);
    printf("Enter the dlno of Driver 2\n");
    scanf("%s", &d2.dlNo);
    printf("Enter the route of Driver 2\n");
    scanf("%s", &d2.route);
    printf("Enter the no of kms of Driver 2\n");
    scanf("%d", &d2.kms);
    printf("\n");

    printf("Enter the name of Driver 3\n");
    scanf("%s", &d3.name);
    printf("Enter the dlno of Driver 3\n");
    scanf("%s", &d3.dlNo);
    printf("Enter the route of Driver 3\n");
    scanf("%s", &d3.route);
    printf("Enter the no of kms of Driver 3\n");
    scanf("%d", &d3.kms);
    printf("\n");

    printf("********* Printing Information of Drivers ********** \n");

    printf("For Driver 1\n");
    printf("Name: %s\n", &d1.name);
    printf("DL No: %s\n", &d1.dlNo);
    printf("Route: %s\n", &d1.route);
    printf("Kms: %d\n", &d1.kms);
    printf("\n");

    printf("For Driver 2\n");
    printf("Name: %s\n", &d2.name);
    printf("DL No: %s\n", &d2.dlNo);
    printf("Route: %s\n", &d2.route);
    printf("Kms: %d\n", &d2.kms);
    printf("\n");

    printf("For Driver 3\n");
    printf("Name: %s\n", &d3.name);
    printf("DL No: %s\n", &d3.dlNo);
    printf("Route: %s\n", &d3.route);
    printf("Kms: %d\n", &d3.kms);
    printf("\n");

    return 0;
}
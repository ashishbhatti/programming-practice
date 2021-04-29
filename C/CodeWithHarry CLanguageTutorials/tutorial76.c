#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

float eDistance(int x1, int y1, int x2, int y2)
{
    float dis = sqrt((pow((y2 - y1), 2)) + (pow((x2 - x1), 2)));
    return dis;
}

float areaOfCircle(int x1, int y1, int x2, int y2, float (*distance)(int x1, int y1, int x2, int y2))
{
    return distance(x1, y1, x2, y2);
}

int main()
{
    // Take coordinate input of two points from the user
    int x1,x2,y1,y2;
    float dst;


    printf("Enter the value of x1\n");
    scanf("%d", &x1);

    printf("Enter the value of y1\n");
    scanf("%d", &y1);

    printf("Enter the value of x2\n");
    scanf("%d", &x2);

    printf("Enter the value of y2\n");
    scanf("%d", &y2);

    dst = areaOfCircle(x1,y1,x2,y2,eDistance);
    printf("The distance between these points is %.2f\n",dst);

    return 0;
}
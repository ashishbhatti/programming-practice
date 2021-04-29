#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

float eDistance(int x1, int y1, int x2, int y2)
{
    float dis = sqrt( (pow((y2-y1),2)) + (pow((x2-x1),2)) );
    return dis;
}

float manDistance(int x1, int y1, int x2, int y2)
{
    float dis =  fabs(y2-y1) + fabs(x2-x1);
    return dis;
}

float areaOfCircle(int x1, int y1, int x2, int y2, float (*fPtr)(int, int, int, int))
{
    return PI * pow(fPtr(x1, y1, x2, y2), 2);
}

int main()
{
    // Take coordinate input of two points from the user
    int x1, y1, x2, y2;
    printf("Enter the integer coordinates of first point as: x y\n");
    scanf("%d %d", &x1, &y1);
    getchar();

    printf("Enter the integer coordinates of second point as: x y\n");
    scanf("%d %d", &x2, &y2);
    getchar();

    float (*ptr)(int, int, int, int);
    ptr = manDistance;

    printf("The area of circle is %f\n",areaOfCircle(x1,y1,x2,y2,ptr));

        return 0;
}
//PREPROCESSOR DIRECTIVES

#include <stdio.h>
#include "tutorial54.c"   //Used for including code from other files
#define PI 3.14           //Used to define preprocessor variablels
#define SQUARE(r) r*r     //Used t define macros, similar to functions but faster


int main()
{
    float var = PI;
    int r = 4;
    int * ptr = functionDangling();
    printf("The value of pi is %f\n", var );
    printf("The area of this circle is %f\n", PI * SQUARE(r));
    
    return 0;
}
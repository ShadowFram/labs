#include <stdio.h>
#include <math.h>
#include "../header/lab1.h"

void lab1(){
    double a, b, c, d, x1,x2;
    do {
    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter c: ");
    scanf("%lf", &c);

    d = pow(b, 2) + -4*(a*c);

    if(d > 0)
    {
    x1 = ((-1 * b) + pow(d, 0.5)) / 2 * a;
    x2 = ((-1 * b) - pow(d, 0.5)) / 2 * a;

    printf("D = %lf.\nx1 = %lf. \nx2 = %lf.\n", d, x1, x2);
    }

    if(d == 0)
    {
    x1 = (-1 * b)/ 2 * a;
    printf("D = %lf.\nx = %lf. \n", d, x1);
    }

    if(d < 0)
    {
    printf("D = %lf.\nD > 0. No roots. \n", d);
    }

    }while(d>=0);
}
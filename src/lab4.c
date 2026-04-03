#include <stdio.h>

#include "../include/lab4.h"

void lab4()
{
    double a,b,c;
    printf("Enter A: ");
    scanf("%lf", &a);

    printf("Enter B: ");
    scanf("%lf", &b);

    printf("Enter C: ");
    scanf("%lf", &c);

    if(tr(a,b,c)) {
        tr_p(a,b,c);
        tr_s(a,b,c);
    } else {
        printf("Empty triangle.");
    }
}

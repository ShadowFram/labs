#include <stdio.h>
#include <math.h>


#ifndef LABS_LAB4_H
#define LABS_LAB4_H

double a,b,c,s1,s,pl;


int tr_p(){
    double per = a+b+c;
    return printf("%lf\n", per);
}

double tr_s(){
    s = (a + b + c)/2;
    //s = s1/2;
    pl = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%lf", pl);
    return 0;
}


void lab4()
{
    printf("Enter A: ");
    scanf("%lf", &a);

    printf("Enter B: ");
    scanf("%lf", &b);

    printf("Enter C: ");
    scanf("%lf", &c);

    tr_p();
    tr_s();

}

#endif //LABS_LAB4_H
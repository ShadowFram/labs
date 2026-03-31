#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "../header/lab4.h"

double tr_p(double a, double b, double c){
    double per = a+b+c;
    return printf("%lf\n", per);
}

double tr_s(double a, double b, double c){
    double s, pl;
    s = (a + b + c)/2;
    //s = s1/2;
    pl = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%lf", pl);
    return 0;
}
_Bool tr(double a, double b, double c){
    return (a+b > c && a+c >b && c+b >a);
}

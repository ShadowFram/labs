#include "../include/lab11.h"
#include <stdarg.h>
#include <float.h>



double sum(int count, ...){
    va_list(args);
    va_start(args, count);

    double total = 0.0;
    for (int i = 0; i < count; i++){
        total += va_arg(args, double);
    }
    va_end(args);
    return total;
}

double max(int count, ...){
    va_list(args);
    va_start(args, count);

    double max = va_arg(args, double);
    for (int i = 0; i < count; i++){
        double current = va_arg(args, double);
        if(current > max) {
            max = current;
        }
    }
    va_end(args);
    return max;
}

double min(int count, ...){
    va_list(args);
    va_start(args, count);

    double min = va_arg(args, double);
    for (int i = 0; i < count; i++){
        double current = va_arg(args, double);
        if(current < min) {
            min = current;
        }
    }
    va_end(args);
    return min;
}

double avg(int count, ...){
    va_list(args);
    va_start(args, count);

    double sum = 0.0;
    double total = 0.0;
    for (int i = 0; i < count; i++){
        sum += va_arg(args, double);
        total = sum/count;
    }
    va_end(args);
    return total;
}
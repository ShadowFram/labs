#include "../include/lab10.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lab10()
{
    char input[256];
    int numbers[100];
    int count = 0;
    printf("Enter numbers through the space: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \t\n");
    while(token != NULL && count < 100){
        numbers[count++] = atoi(token);
        token = strtok(NULL, " \t\n");
    }

    MAXNUM(numbers, count);

}
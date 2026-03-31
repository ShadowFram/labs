#include <stdio.h>
#include <string.h>
#include "../header/lab3.h"

void lab3() {
    char str[81];
    printf("Enter string: ");
    fgets(str, 81,stdin);


    int i, len;
    len = strlen(str);
    i = 0;
    while (i < len) {
        if (str[i] == 'a') {
            str[i] = 'A';
        }
        if (str[i] == 'b') {
            str[i] = 'B';
        }
        i = i + 1;
    }
    printf("Result: %s", str);
}
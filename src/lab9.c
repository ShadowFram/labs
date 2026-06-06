#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_number(char *s) {
    if (*s == '-') s++;

    int has_digit = 0;

    while (*s) {
        if (!isdigit(*s) && *s != '.') {
            return 0;
        }

        if (isdigit(*s)) {
            has_digit = 1;
        }

        s++;
    }

    return has_digit;
}

int lab9() {
    char expr[256];
    char expr1[512];
    char *token;

    double numbers[128];
    char ops[128];

    int numCount = 0;
    int opCount = 0;

    printf("Enter expression: ");
    scanf(" %[^\n]", expr);

    int j = 0;

    for (int i = 0; expr[i]; i++) {

        if (strchr("+-*/", expr[i])) {

            expr1[j++] = ' ';
            expr1[j++] = expr[i];
            expr1[j++] = ' ';
        }
        else {
            expr1[j++] = expr[i];
        }
    }

    expr1[j] = '\0';

    token = strtok(expr1, " ");

    while (token) {

        if (is_number(token)) {
            numbers[numCount++] = atof(token);
        }
        else if (strlen(token) == 1 &&
                 strchr("+-*/", token[0])) {

            ops[opCount++] = token[0];
        }

        token = strtok(NULL, " ");
    }

    for (int i = 0; i < opCount; ) {

        if (ops[i] == '*' || ops[i] == '/') {

            double value;

            if (ops[i] == '*') {
                value = numbers[i] * numbers[i + 1];
            }
            else {

                if (numbers[i + 1] == 0) {
                    printf("Division by zero!\n");
                    return 1;
                }

                value = numbers[i] / numbers[i + 1];
            }

            numbers[i] = value;

            for (int k = i + 1; k < numCount - 1; k++) {
                numbers[k] = numbers[k + 1];
            }

            for (int k = i; k < opCount - 1; k++) {
                ops[k] = ops[k + 1];
            }

            numCount--;
            opCount--;
        }
        else {
            i++;
        }
    }

    double result = numbers[0];

    for (int i = 0; i < opCount; i++) {

        if (ops[i] == '+') {
            result += numbers[i + 1];
        }
        else if (ops[i] == '-') {
            result -= numbers[i + 1];
        }
    }

    printf("Result: %g\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_number(char *s) {
    if (*s == '-') s++;
    while (*s) {
        if (!isdigit(*s) && *s != '.') return 0;
        s++;
    }
    return 1;
}

int lab9() {
    char expr[256], expr1[512], *token;
    double result = 0, num;
    char op;
    int i, j = 0;

    printf("Enter expression: ");
    scanf("%[^\n]", expr);

    // Добавляем пробелы вокруг операторов
    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            if (i > 0 && expr[i-1] != '+' && expr[i-1] != '-') {
                expr1[j++] = ' ';
            }
            expr1[j++] = expr[i];
            expr1[j++] = ' ';
        } else {
            expr1[j++] = expr[i];
        }
    }
    expr1[j] = '\0';

    token = strtok(expr1, " \n");
    while (token) {
        if (*token == '+' || *token == '-') {
            op = *token;
        }
        if (is_number(token)) {
            num = atof(token);
            if (op == '+') result += num;
            else result -= num;
        }
        token = strtok(NULL, " \n");
    }

    printf("Result: %g\n", result);
    return 0;
}

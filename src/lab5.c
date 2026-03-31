#include <stdio.h>
#include <stdlib.h>
#include "../header/lab5.h"

double lab5(){

    int n;
    char operator;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    if(n <= 0) printf("N must be more than 0.\n");

    double** matrix1 = (double**)malloc(n*(sizeof(double*)));

    if (matrix1 == NULL) {printf("ERROR. Memory was break.\n"); return 1;}

    for(int i = 0; i < n; i++){
        matrix1[i] = (double *) (double **) malloc(n * sizeof(double));

        if(matrix1[i] == NULL) {
            printf("ERROR. Memory was break.");

            for(int j = 0; j <n; j++) free(matrix1[j]);

            free(matrix1);
            return 1;
        }

    }

    double** matrix2 = (double**)malloc(n*(sizeof(double*)));

    if (matrix2 == NULL) {
        printf("ERROR. Memory was break.\n");
        free_matrix(matrix1,n);
        return 1;
    }

    for(int i = 0; i < n; i++){
        matrix2[i] = (double *) (double **) malloc(n * sizeof(double));

        if(matrix2[i] == NULL) {
            printf("ERROR. Memory was break.");

            for(int j = 0; j <n; j++) free(matrix2[j]);

            free(matrix2);
            free_matrix(matrix1, n);
            return 1;
        }

    }

    input_matrix(matrix1, n, "A");
    input_matrix(matrix2, n, "B");

    printf("Enter operand (+, -, *): ");
    scanf(" %c", &operator);

    if (operator != '+' && operator != '-' && operator != '*') {
        printf("ERROR. Wrong operator.\n");
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
        return 1;
    }

    double** result = calculate_matrix(matrix1, matrix2, n, operator);

    if (result == NULL) {
        printf("Error. Wrong result.\n");
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
        return 1;
    }

    print_matrix(matrix1, n, "Matrix A");
    print_matrix(matrix2, n, "Matrix B");

    switch(operator) {
        case '+':
            print_matrix(result, n, "Result of matrix (A + B)");
            break;
        case '-':
            print_matrix(result, n, "Result of matrix (A - B)");
            break;
        case '*':
            print_matrix(result, n, "Result of matrix (A * B)");
            break;
    }

    // Освобождение памяти
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(result, n);

    return 0;

}
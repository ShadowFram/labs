#include <stdio.h>
#include <stdlib.h>
#include "../include/lab5.h"

double** calculate_matrix(double** matrix1, double** matrix2, int n, char operator){

    // Выделение памяти.

    double **result;
    result = (double **) malloc(n * sizeof(double*));
    if (result == NULL) return NULL;


    // Очистка памяти.

    for (int i = 0; i<n; i++){
        result[i] = (double*) malloc(n * sizeof(double));
        if (result[i] == NULL){
            for (int j = 0; j < i; j++){
                free(result[j]);
            }
            free(result);
            return NULL;
        }
    }

    switch(operator) {

        case '+':

            // Сложение матриц

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;

        case '-':

            // Вычитание матриц

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;

        case '*':

            // Умножение матриц

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < n; k++) {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            break;

        default:
            // ERROR
            for (int i = 0; i < n; i++) {
                free(result[i]);
            }
            free(result);
            return NULL;
    }

    return result;
}

void free_matrix(double** matrix, int n){
    if (matrix == NULL) return;

    for(int i = 0; i < n; i++){ free(matrix[i]);}
    free(matrix);
}

void input_matrix(double** matrix, int n, const char* name) {
    printf("\nEnter Matrix: %s:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}


void print_matrix(double** matrix, int n, const char* name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
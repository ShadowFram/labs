#pragma once

double** calculate_matrix(double** matrix1, double** matrix2, int n, char operator);
void free_matrix(double** matrix, int n);
void input_matrix(double** matrix, int n, const char* name);
void print_matrix(double** matrix, int n, const char* name);
double lab5();
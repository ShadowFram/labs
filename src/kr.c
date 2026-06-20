#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/kr.h"


int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int m, int y) {
    int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (m == 2 && is_leap(y)) ? 29 : d[m-1];
}

long to_days(int d, int m, int y) {
    long t = d;
    for (int i = 1; i < y; i++) t += is_leap(i) ? 366 : 365;
    for (int i = 1; i < m; i++) t += days_in_month(i, y);
    return t;
}

double **inputm(int n){
    int i,j;
    double **mat = (double **)malloc(n * sizeof(double *));

    for(i = 0; i < n; i++){
        mat[i] = (double *)malloc(n * sizeof(double));
        for(j=0;j<n;j++){
            mat[i][j] = rand() % 100;
        }
    }
    return mat;
}

void printm(double **mat, int n, FILE *f){
    int i,j;
    for (i =0;i<n;i++){
        fprintf(f, "\n");
        for(j=0;j<n;j++){
            fprintf(f, "%.2lf ", mat[i][j]);
        }
    }
    fprintf(f, "\n");
}

double sum(double **mat, int n){
    int s = 0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            s+=mat[i][j];
        }
    }
    return s;
}

void kr(){
    srand((unsigned)time(NULL));
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    FILE *fin = fopen("../data/input.txt", "r");
    if (!fin) {
        fin = fopen("../data/input.txt", "w");
        fprintf(fin, "31.12.2026\n");
        fclose(fin);
        fin = fopen("../data/input.txt", "r");
    }
    int d, m, y;
    fscanf(fin, "%d.%d.%d", &d, &m, &y);
    fclose(fin);

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    long diff = to_days(d, m, y) - to_days(tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900);
    printf("days until %02d.%02d.%04d: %ld\n\n", d, m, y, diff);


    int n, c=0;
    double **matrices[100], sums[100];
    printf("ENTER N: ");
    scanf("%d", &n);

    int pair =0;
    int indx1= -1, indx2=-1;

    while (!pair){
        double **mat = inputm(n);
        double s = sum(mat, n);

        for (int i=0;i<c;i++){
            if(sums[i] == s){
                indx1=i;
                indx2=c;
                pair = 1;
                break;
            }
        }
        matrices[c] =mat;
        sums[c] = s;
        c++;
        if(c>=99) break;
    }
    FILE *f = fopen("../data/output.txt", "w");

    fprintf(f, "mat #%d (sum = %f):\n", indx1 + 1, sums[indx1]);
    printm(matrices[indx1], n, f);

    fprintf(f, "mat #%d (sum = %f):\n", indx2 + 1, sums[indx2]);
    printm(matrices[indx2], n, f);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    double elapsed = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / 1e9;
    printf("time: %.6f sec\n", elapsed);

}
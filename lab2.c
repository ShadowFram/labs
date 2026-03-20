#include <stdio.h>

int main()
{
    int N = 3;
    double matrix[N][N];

    double main_sum = 0.0;
    double second_sum = 0.0;

    double sqrl_mat1 = 0.0;
    double sqrl_mat2 = 0.0;
    double sqrl_mat3 = 0.0;
    double sqrl_mat4 = 0.0;

    int i, j;

    printf("Enter matrix size(2/3): ");
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("Enter [%d][%d]:", i, j);
            scanf("%lf ", &matrix[i][j]);
        }
    }

    if(N == 3) {
        for (i = 0; i < N; i++) {

            for (j = 0; j < N; j++) {

                printf("%lf ", matrix[i][j]);
                main_sum = matrix[0][0] + matrix[1][1] + matrix[2][2];
                second_sum = matrix[0][2] + matrix[1][1] + matrix[2][0];
            }
            printf("\n");
        }

        printf("main sum = %lf.\nsecond_sum = %lf.", main_sum, second_sum);
    }

    if(N == 2) {
        for (i = 0; i < N; i++) {

            for (j = 0; j < N; j++) {

                printf("%lf ", matrix[i][j]);
                main_sum = matrix[0][0] + matrix[1][1];
                second_sum = matrix[0][2] + matrix[1][1];
            }
            printf("\n");
        }

        sqrl_mat1 = matrix[0][0]*matrix[0][0] + matrix[0][1]*matrix[1][0]; // x11
        sqrl_mat2 = matrix[1][0]*matrix[0][1] + matrix[1][1]*matrix[1][0]; // x12

        sqrl_mat3 = matrix[0][0]*matrix[0][1] + matrix[0][1]*matrix[1][1]; // x21
        sqrl_mat4 = matrix[1][0]*matrix[0][1] + matrix[1][1]*matrix[1][1]; // x22

        printf("\nSQRL MATRIX:\n");
        printf("%lf %lf\n%lf %lf\n", sqrl_mat3, sqrl_mat4, sqrl_mat1, sqrl_mat2);

        printf("\nmain sum = %lf.\nsecond_sum = %lf.", main_sum, second_sum);
    }

    return 0;
}
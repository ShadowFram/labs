#include <stdio.h>

int main()
{
    int N;
   

    double main_sum = 0.0;
    double second_sum = 0.0;

    double sqrl_mat1 = 0.0;
    double sqrl_mat2 = 0.0;
    double sqrl_mat3 = 0.0;
    double sqrl_mat4 = 0.0;
   

    int i, j, k;

    printf("Enter matrix size(2/3): ");
    scanf("%d", &N);
    
 	double matrix[N][N];
 	double result[N][N];
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf(" %lf", &matrix[i][j]);
        }
    }


    	
	for(i=0; i < N; i++){
		
		main_sum += matrix[i][i];
		second_sum += matrix[i][N-i-1];
		
	}
		printf("\n");
		printf("main sum = %lf.\nsecond_sum = %lf.\n\n", main_sum, second_sum);
	for (k = 0; k < N; k++) {

        for (j = 0; j < N; j++) {

            printf("%lf ", matrix[k][j]);
			result[i][j] = 0;
        }
        printf("\n");
    }	

	for(i =0;i < N; i++){
		for(j=0; j < N; j++){
			for(k=0;k<N;k++){
				result[i][j] += matrix[i][k] * matrix[k][j];				
			}
			
		}

	}
	printf("\n");
	for (i = 0; i < N; i++) {

        for (j = 0; j < N; j++) {

            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }
    main_sum = 0.0;
    second_sum = 0.0;
    	for(i=0; i < N; i++){
		
		main_sum += result[i][i];
		second_sum += result[i][N-i-1];
		
	}
    

 

//        sqrl_mat1 = matrix[0][0]*matrix[0][0] + matrix[0][1]*matrix[1][0]; // x11
//        sqrl_mat2 = matrix[1][0]*matrix[0][1] + matrix[1][1]*matrix[1][0]; // x12
//
//        sqrl_mat3 = matrix[0][0]*matrix[0][1] + matrix[0][1]*matrix[1][1]; // x21
//        sqrl_mat4 = matrix[1][0]*matrix[0][1] + matrix[1][1]*matrix[1][1]; // x22

        printf("\nmain sum = %lf.\nsecond_sum = %lf.", main_sum, second_sum);
    

    return 0;
}

#include <stdio.h>

int main()
{
	int N = 3;
	double matrix[N][N];

	double main_sum = 0.0;
	double second_sum = 0.0;
	
	int i, j;
	
	for(i = 0; i < N; i++){
		
		for(j = 0; j < N; j++){
			
			scanf("%lf ", &matrix[i][j]);
		}
	}
	
	for(i = 0; i < N; i++){
		
		for(j = 0; j < N; j++){
			
			printf("%lf ", matrix[i][j]);
			main_sum = matrix[0][0] + matrix[1][1] + matrix[2][2];
			second_sum = matrix[0][2] + matrix[1][1] + matrix[2][0];
		}
		printf("\n");
	}
	printf("main sum = %lf.\nsecond_sum = %lf.", main_sum, second_sum);
	
	return 0;
}

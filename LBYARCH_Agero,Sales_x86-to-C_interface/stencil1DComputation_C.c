#include <stdio.h>
#include <stdlib.h>
#define WINDOW_SIZE 7

int main() {
	int length = 9;
    float X[20] = {1,2,3,4,5,6,7,8,9}; // vector

	int arrYSize = (length - 7) + 1;
    float* Y = (float*)malloc(arrYSize * sizeof(float));

    int offset = 0;

    for (int k = 0; k < arrYSize; k++) {
        
        float sum = 0;
        
        for (int i = offset; i < WINDOW_SIZE+offset;  i++) {
            sum += X[i];
            printf("sum: %f ; X[i] %f\n", sum, X[i]);
        }
        
        Y[k] = sum;
        printf("Y[%d] = %f\n", k, sum);
        offset++;
    }
	
	printf("Output vector Y: ");
    for (int i = 0; i < arrYSize; i++) {
        printf("%f ", Y[i]);
    }

	
	
	return 0;
}
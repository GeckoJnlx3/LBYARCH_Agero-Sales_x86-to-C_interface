#include <stdio.h>
#include <stdlib.h>
#define WINDOW_SIZE 7

extern float* stencil1DComputation(long long int n, float X[]);

int main() {
	int n = 8;
	float* X = (float*)malloc(n * sizeof(float));
	
	int arrYSize = (n - 7) + 1;
	float* Y = (float*)malloc(arrYSize * sizeof(float));

	Y = stencil1DComputation(n, X);

	for (int i = 0; i < arrYSize; i++) {
		printf("%.3f", Y[i]);
	}

	return 0;
}
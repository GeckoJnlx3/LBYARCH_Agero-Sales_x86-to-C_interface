#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define WINDOW_SIZE 7

extern float stencil1DComputation(long long int offset, float X[]);

int main() {
    double n = pow(2,5);
    float* X = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        X[i] = (float)i+1;
    }

    int offset = 0;

    int arrYSize = ((int)n - 7) + 1;
    float* Y = (float*)malloc(arrYSize * sizeof(float));
    
    clock_t start, end;
    double total;
    start = clock();

    for (int i = 0; i < arrYSize; i++) {
        Y[i] = stencil1DComputation(offset, X);
        offset++;
    }
    
    end = clock();

    printf("ASM + C. Length: %.0lf\nY[] = ", n);
    for (int i = 0; i < arrYSize; i++) {
        printf("%.3f\n ", Y[i]);
    }

    total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total time : %lf\n", total);

    return 0;
}

void stencil1DComputationC(long long int arrYSize, float X[], float* Y) {
    long long int offset = 0;

    for (int k = 0; k < arrYSize; k++) {

        float sum = 0;

        for (int i = offset; i < WINDOW_SIZE + offset; i++) {
            sum += X[i];
        }

        Y[k] = sum;
        offset++;
    }
}
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define WINDOW_SIZE 7

extern float stencil1DComputation(long long int offset, float X[]);

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

int main() {
    double n = pow(2,20);
    float* X = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        X[i] = (float)i+1;
    }

    int offset = 0;

    int arrYSize = ((int)n - 7) + 1;
    float* Y_ASM = (float*)malloc(arrYSize * sizeof(float));
    
    clock_t start_ASM, end_ASM;
    double total_ASM;
    start_ASM = clock();

    for (int i = 0; i < arrYSize; i++) {
        Y_ASM[i] = stencil1DComputation(offset, X);
        offset++;
    }
    
    end_ASM = clock();

    clock_t start_C, end_C;
    double total_C;
    start_C = clock();
    float* Y_C = (float*)malloc(arrYSize * sizeof(float));

    stencil1DComputationC(arrYSize, X, Y_C);
    end_C = clock();

    //Comparative printing of output
    printf("ASM + C vs Pure C. Length: %.0lf\n", n);
    printf("Values of Y[]:\n");
    printf("ASM + C \t\tPure C\n");

    int printLength = arrYSize < 10 ? arrYSize : 10;

    for (int i = 0; i < printLength; i++) {
        printf("%.3f\t\t%.3f\n ", Y_ASM[i], Y_C[i]);
    }
    
    total_ASM = (double)(end_ASM - start_ASM) / CLOCKS_PER_SEC;
    total_C = (double)(end_C - start_C) / CLOCKS_PER_SEC;

    //comparative printing of time
    printf("\nTime taken (in seconds): \n");
    printf("ASM + C \tPure C\n");
    printf("%.3f\t\t%.3f\n", total_ASM, total_C);

    return 0;
}


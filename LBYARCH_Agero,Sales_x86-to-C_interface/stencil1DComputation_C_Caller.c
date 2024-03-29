#include <stdio.h>
#include <stdlib.h>
#define WINDOW_SIZE 7

extern float stencil1DComputation(long long int offset, float X[]);

int main() {
    int n = 10;
    float* X = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        X[i] = i+1;
    }

    int offset = 0;

    int arrYSize = (n - 7) + 1;
    float* Y = (float*)malloc(arrYSize * sizeof(float));

    for (int i = 0; i < arrYSize; i++) {
        Y[i] = stencil1DComputation(offset, X);
        offset++;
    }

    for (int i = 0; i < arrYSize; i++) {
        printf("%.3f\n", Y[i]);
    }


    return 0;
}
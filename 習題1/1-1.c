#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 3;

    double matrix1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double matrix2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    double result[rows * cols];
    
    double transposed[cols * rows];
    transpose(matrix1, transposed, rows, cols);
    printf("Transposed matrix:\n");
    dump(transposed, cols, rows);

    add(matrix1, matrix2, result, rows, cols);
    printf("\nMatrix addition result:\n");
    dump(result, rows, cols);

    int cols2 = 2;
    double product[rows * cols2];
    multiply(matrix1, matrix2, product, rows, cols, cols2);
    printf("\nMatrix multiplication result:\n");
    dump(product, rows, cols2);

    return 0;
}

void transpose(double *input, double *output, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j * rows + i] = input[i * cols + j];
        }
    }
}

void add(double *matrix1, double *matrix2, double *result, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        result[i] = matrix1[i] + matrix2[i];
    }
}

void multiply(double *matrix1, double *matrix2, double *result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i * cols2 + j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i * cols2 + j] += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
            }
        }
    }
}

void dump(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}
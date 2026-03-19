#include "matrix_ops.h"
#include <iostream>

double** allocateMatrix(int n) {
    double** matrix = new double* [n];
    for (int i = 0; i < n; ++i) matrix[i] = new double[n];
    return matrix;
}

void freeMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) delete[] matrix[i];
    delete[] matrix;
}

void inputMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];
}

void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

double** calculateMatrix(double** m1, double** m2, int n, char op) {
    double** result = allocateMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (op == '+') result[i][j] = m1[i][j] + m2[i][j];
            else if (op == '-') result[i][j] = m1[i][j] - m2[i][j];
            else if (op == '*') {
                result[i][j] = 0;
                for (int k = 0; k < n; ++k)
                    result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

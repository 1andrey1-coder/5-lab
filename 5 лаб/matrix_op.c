#include <stdlib.h>
#include "matrix_op.h"
//double** res = (double**)malloc(n * sizeof(double*)); массив из n элементов
//res[i] = (double*)malloc(n * sizeof(double)); выделение памяти под i(строка)


double** calculateMatrix(double** a, double** b, int n, char op) {
    double** res = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        res[i] = (double*)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (op == '+') {
                res[i][j] = a[i][j] + b[i][j];
            } else if (op == '-') {
                res[i][j] = a[i][j] - b[i][j];
            } else if (op == '*') {
                res[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    return res;
}

#include <stdio.h>
#include <stdlib.h>
#include "matrix_op.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    int n;
    char op;

    printf("Введите размер матриц n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некорректный размер\n");
        return 1;
    }

    double** a = (double**)malloc(n * sizeof(double*));
    double** b = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        a[i] = (double*)malloc(n * sizeof(double));
        b[i] = (double*)malloc(n * sizeof(double));
    }

    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    printf("Введите знак операции (+, -, *): ");
    scanf(" %c", &op);

    if (op != '+' && op != '-' && op != '*') {
        printf("Неверная операция\n");
        return 1;
    }

    double** result = calculateMatrix(a, b, n, op);

    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(result[i]);
    }
    free(a);
    free(b);
    free(result);

    return 0;
}

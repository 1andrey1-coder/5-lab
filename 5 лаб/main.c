#include <stdio.h>
#include <stdlib.h>



double** calculate_matrices(double** a, double** b, int n, char op) {
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


int main() {
    int n;
    char op;

    printf("Введите размерность матриц n: ");
    if (scanf("%d", &n) != 1) return 1;

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

    double** result = calculate_matrices(a, b, n, op);

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

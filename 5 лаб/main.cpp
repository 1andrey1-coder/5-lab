#include <iostream>
#include "matrix_ops.h"
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int n;
    char op;
    std::cout << "¬ведите размер матрицы N: ";
    std::cin >> n;

    double** mat1 = allocateMatrix(n);
    double** mat2 = allocateMatrix(n);

    std::cout << "¬ведите элементы дл€ матрицы 1:" << std::endl;
    inputMatrix(mat1, n);
    std::cout << "¬ведите элементы дл€ матрицы 2:" << std::endl;
    inputMatrix(mat2, n);

    std::cout << "¬ведите операцию (+, -, *): ";
    std::cin >> op;

    double** res = calculateMatrix(mat1, mat2, n, op);

    std::cout << "–езультат:" << std::endl;
    printMatrix(res, n);

    freeMatrix(mat1, n);
    freeMatrix(mat2, n);
    freeMatrix(res, n);

    return 0;
}

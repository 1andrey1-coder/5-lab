#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

double** allocateMatrix(int n);
void freeMatrix(double** matrix, int n);
void inputMatrix(double** matrix, int n);
void printMatrix(double** matrix, int n);
double** calculateMatrix(double** m1, double** m2, int n, char op);

#endif

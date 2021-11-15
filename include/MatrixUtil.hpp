#ifndef MATRIX_UTIL_H
#define MATRIX_UTIL_H
#include <vector>

#include "Matrix.hpp"

class MatrixUtil{

public:
    Matrix static fill(int x, int y, std::vector<std::vector<int>> mat);
    void static calculate(int n1, int m1, int n2, int m2, std::string nameMatrix1, std::string nameMatrix2);
    void static  saveToFile(Matrix *mat, std::string nome);
};

#endif
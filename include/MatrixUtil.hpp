#ifndef MATRIX_UTIL_H
#define MATRIX_UTIL_H
#include <vector>

#include "Matrix.hpp"

class MatrixUtil{

public:
    Matrix static fill(int x, int y, std::vector<std::vector<int>> mat);
    Matrix static calculate(std::string mat1, std::string mat2);
    void static  saveToFile(Matrix *mat, std::string nome);
};

#endif
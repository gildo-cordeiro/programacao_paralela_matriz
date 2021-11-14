#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <chrono>

class Matrix{
private:
    int x, y;
    std::vector<std::vector<int>> mat;
    double time;

public:
    Matrix();
    ~Matrix();

    Matrix(int x, int y, std::vector<std::vector<int>> mat, double time);
    std::vector<std::vector<int>> getMat();
    int getX();
    int getY();
    double getTime();
};

#endif
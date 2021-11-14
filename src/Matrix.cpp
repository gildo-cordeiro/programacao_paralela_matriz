#include "Matrix.hpp"

Matrix::Matrix(){}

Matrix::~Matrix(){}

Matrix::Matrix(int x, int y, std::vector<std::vector<int>> mat, double time){
    this->x = x;
    this->y = y;
    this->mat = mat;
    this->time = time;
}

std::vector<std::vector<int>> Matrix::getMat(){
    return this->mat;
}

int Matrix::getX(){
    return this->x;
}

int Matrix::getY(){
    return this->y;
}

double Matrix::getTime(){
    return this->time;
}

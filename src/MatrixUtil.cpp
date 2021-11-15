#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <map>

#include "MatrixUtil.hpp"

/**
 * @brief Fills a matrix received by parameter according to its dimensions
 * 
 * @param x 
 * @param y 
 * @param mat 
 */
Matrix MatrixUtil::fill(int x, int y, std::vector<std::vector<int>> mat){
    for(int i = 0; i < x; i++){
        mat.push_back(std::vector<int>());

        for(int j = 0; j < y; j++)
            mat[i].push_back(rand()%10 + 1);
    }

    return Matrix(x, y, mat, 0);

}

/**
 * @brief 
 * 
 * @param n1 
 * @param m1 
 * @param n2 
 * @param m2 
 * @param nameMatrix1 
 * @param nameMatrix2 
 */
void MatrixUtil::calculate(int n1, int m1, int n2, int m2, std::string nameMatrix1, std::string nameMatrix2){
    std::vector<std::vector<int>> firstMatrix, secondMatrix;

    Matrix mat1 = MatrixUtil::fill(n1, m1, firstMatrix);   
    MatrixUtil::saveToFile(&mat1, nameMatrix1);       

    Matrix mat2 = MatrixUtil::fill(n2, m2, secondMatrix);  
    MatrixUtil::saveToFile(&mat2, nameMatrix2);     
}

/**
 * @brief Save file txt with results
 * 
 * @param mat 
 * @param name 
 */
void MatrixUtil::saveToFile(Matrix* mat, std::string name){
    std::ofstream out;
    if(out){
        out.open(name);
        out << mat->getX() << " " << mat->getY();
        for(int i = 0; i < mat->getX(); i++){
            for(int j = 0; j < mat->getY(); j++)
                out << "\nC" << i+1 <<  j+1 << " " << mat->getMat()[i][j];
        }
        if(mat->getTime() != 0){
            out << "\n" << mat->getTime() << "[MS]";
        }

        out.close();
    }else{
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
}
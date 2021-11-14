#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "MatrixUtil.hpp"
#include "CalcularMatrizSequencial.hpp"

/**
 * @brief Construct a new Calcular Matriz Sequencial:: Calcular Matriz Sequencial object
 * 
 */
CalcularMatrizSequencial::CalcularMatrizSequencial(){}

/**
 * @brief Calculates the sequential value of matrix
 * 
 * @param n1 
 * @param m1 
 * @param n2 
 * @param m2 
 */
void CalcularMatrizSequencial::calculate(int n1, int m1, int n2, int m2){
    const std::string nameMatrix1 = "M1.txt";
    const std::string nameMatrix2 = "M2.txt";
    const std::string nameMatrix3 = "RESULTADO.txt";
    std::vector<std::vector<int>> firstMatrix, secondMatrix;

    Matrix mat1 = MatrixUtil::fill(n1, m1, firstMatrix);   
    MatrixUtil::saveToFile(&mat1, nameMatrix1);       

    Matrix mat2 = MatrixUtil::fill(n2, m2, secondMatrix);  
    MatrixUtil::saveToFile(&mat2, nameMatrix2);    

    Matrix mat3 = MatrixUtil::calculate(nameMatrix1, nameMatrix2); 
    MatrixUtil::saveToFile(&mat3, nameMatrix3);    
 
}
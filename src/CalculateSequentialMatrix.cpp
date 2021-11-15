#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <map>
#include "MatrixUtil.hpp"
#include "CalculateSequentialMatrix.hpp"

/**
 * @brief Construct a new Calcular Matriz Sequencial:: Calcular Matriz Sequencial object
 * 
 */
CalculateSequentialMatrix::CalculateSequentialMatrix(){}

/**
 * @brief Destroy the Calculate Sequential Matrix:: Calculate Sequential Matrix object
 * 
 */
CalculateSequentialMatrix::~CalculateSequentialMatrix(){}

/**
 * @brief Calculates the sequential value of matrix
 * 
 * @param n1 
 * @param m1 
 * @param n2 
 * @param m2 
 */
void CalculateSequentialMatrix::calculate(std::string m1, std::string m2, std::string m3){
    std::ifstream file1, file2;
    std::string line1, line2;
    std::map<std::string, int> mapMatrix1, mapMatrix2;
    int count = 0, rowA = 0, rowB = 0 , colB = 0;

    file1.open(m1, std::ios::in);
    if(!file1){
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    while (!file1.eof() ){
        std::getline(file1,line1);
        if(count == 0){
            rowA = std::stoi(line1.substr(0,1));
        }else{
            mapMatrix1[line1.substr(0,3)] = std::stoi(line1.substr(4, '\n'));
        }        
        count++;
    }
    file1.close();

    file2.open(m2, std::ios::in);
    count = 0;
    while (!file2.eof() ){
        std::getline(file2,line2);
        if(count == 0){
            rowB = std::stoi(line2.substr(0,1));
            colB = std::stoi(line2.substr(2,'\n'));
        }else{
            mapMatrix2[line2.substr(0,3)] = std::stoi(line2.substr(4, '\n'));
        }        
        count++;
    }

    std::vector<std::vector<int>> matrix;

    file2.close();
    int value = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for (int i = 0; i < rowA; i++){
        matrix.push_back(std::vector<int>());
        for (int j = 0; j < colB; j++){

            value = 0;
            for(int x = 0; x < rowB; x++) {
                std::string key1 = "C"+std::to_string(i+1)+std::to_string(x+1);
                std::string key2 = "C"+std::to_string(x+1)+std::to_string(j+1);
                value += mapMatrix1[key1] * mapMatrix2[key2];
			}
            matrix[i].push_back(value);
        }        
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    double time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    Matrix a = Matrix(rowA, colB, matrix, time);
    MatrixUtil::saveToFile(&a, m3);    
 
}